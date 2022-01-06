#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
using namespace std;
enum token_type
{
	unknown_type = 0,
	LeftBrace,
	RightBrace,
	TokString,
	Comma,
	Colon
};

enum node_type
{
	ErrorType = 0,
	Root,
	NotExist,
	NodeString,
	NodeObj,
};

list<string> str_search_list; // this list is set for search-function of node
struct node
{
	int type;
	string context;
	list<node> children;
	node &operator=(const node &p)
	{
		type = p.type;
		context = p.context;
		children = p.children;
		return *this;
	}
	void child_search(list<string>::iterator &iter)
	{
		for (list<node>::iterator i = this->children.begin(); i != this->children.end(); ++i)
			if (i->context == *iter)
			{
				switch (i->type)
				{
				case NodeString:
					cout << "STRING " << i->children.front().context << endl;
					return;
					break;
				case NodeObj:
					++iter;
					if (iter == str_search_list.end())
						cout << "OBJECT" << endl;
					else
						i->child_search(iter);
					return;
					break;
				}
			}
		cout << "NOTEXIST" << endl;
		return;
	}
	void root_search()
	{
		list<string>::iterator iter = str_search_list.begin();
		for (list<node>::iterator i = this->children.begin(); i != this->children.end(); ++i)
			if (i->context == *iter)
			{
				switch (i->type)
				{
				case NodeString:
					cout << "STRING " << i->children.front().context << endl;
					return;
					break;
				case NodeObj:
					++iter;
					if (iter == str_search_list.end())
						cout << "OBJECT" << endl;
					else
						i->child_search(iter);
					return;
					break;
				}
			}
		cout << "NOTEXIST" << endl;
		return;
	}

};

struct token
{
	int type;
	string context;
};

list<char> resource;
list<token> token_list;
list<token>::iterator this_token;
string temp_string;
node root;

bool lexer() //词法分析
{
	// scan the whole resource code and generate tokens
	string tmp;
	for (list<char>::iterator iter = resource.begin(); iter != resource.end(); ++iter)
	{
		token temp_token;
		if (*iter == '{')
		{
			temp_token.type = LeftBrace;
			temp_token.context = "{";
			token_list.push_back(temp_token);
		}
		else if (*iter == '}')
		{
			temp_token.type = RightBrace;
			temp_token.context = "}";
			token_list.push_back(temp_token);
		}
		else if (*iter == ',')
		{
			temp_token.type = Comma;
			temp_token.context = ",";
			token_list.push_back(temp_token);
		}
		else if (*iter == ':')
		{
			temp_token.type = Colon;
			temp_token.context = ":";
			token_list.push_back(temp_token);
		}
		else if (*iter == '\"')
		{
			++iter;
			tmp = "";
			while (*iter != '\"')
			{
				if (*iter == '\\')
				{
					++iter;
					if (iter != resource.end() && (*iter == '\\' || *iter == '\"'))
						tmp += *iter;
					else
					{
						// '\\' with no '\\' or '\"' after it
						cout << "[error] incorrect string: " << tmp << "\\" << endl;
						return false;
					}
				}
				else
					tmp += *iter;
				++iter;
				if (iter == resource.end() || *iter == '\n')
				{
					// string with an incorrect end
					cout << "[error] incorrect string: " << tmp << " . must end with a \'\"\' ." << endl;
					return false;
				}
			}
			temp_token.type = TokString;
			temp_token.context = tmp;
			token_list.push_back(temp_token);
		}
	}
	return true;
}

node node_gen()
{
	node ret;
	ret.type = ErrorType;
	++this_token;
	if (this_token->type == TokString)
	{
		ret.type = NodeString;
		ret.context = this_token->context;
	}
	else if (this_token->type == LeftBrace)
	{
		ret.type = NodeObj;
		while (this_token != token_list.end())
		{
			++this_token;
			if (this_token == token_list.end())
			{
				cout << "[error] expect a '}' at the end." << endl;
				ret.type = ErrorType;
				return ret;
			}
			// }
			if (this_token->type == RightBrace)
				break;
			if (this_token->type == TokString)
			{
				node tmp;
				tmp.context = this_token->context;
				++this_token;
				// :
				if (this_token == token_list.end() || this_token->type != Colon)
				{
					cout << "[error] expect a \':\' this token: " << tmp.context << endl;
					ret.type = ErrorType;
					return ret;
				}
				++this_token;
				if (this_token == token_list.end() || (this_token->type != TokString && this_token->type != LeftBrace))
				{
					cout << "[error] expect a string or object after this token: " << tmp.context << endl;
					ret.type = ErrorType;
					return ret;
				}
				switch (this_token->type)
				{
				// string must get a child typed string
				case TokString:
					tmp.type = NodeString;
					--this_token;
					tmp.children.push_back(node_gen());
					break;
				// object get a return type object so it's children list must set to the same as return object
				case LeftBrace:
					tmp.type = NodeObj;
					--this_token;
					tmp.children = node_gen().children;
					break;
				}
				// if get error type ,parse failed
				if (tmp.children.back().type == ErrorType)
				{
					ret.type = ErrorType;
					return ret;
				}
				ret.children.push_back(tmp);
				++this_token;
				if (this_token->type == RightBrace)
					--this_token;
				else if (this_token->type != Comma)
				{
					cout << "[error] expect a \',\' here." << endl;
					ret.type = ErrorType;
					return ret;
				}
			}
		}
	}
	else
		cout << "[error] unknown type." << endl;
	return ret;
}

bool parse() //语法分析
{
	root.type = Root;
	this_token = token_list.begin();
	// {
	if (this_token->type != LeftBrace)
	{
		cout << "[error] expect a '{' at the beginning." << endl;
		return false;
	}
	while (this_token != token_list.end())
	{
		++this_token;
		if (this_token == token_list.end())
		{
			cout << "[error] expect a '}' at the end." << endl;
			return false;
		}
		// }
		if (this_token->type == RightBrace)
			break;
		if (this_token->type == TokString)
		{
			node tmp;
			tmp.context = this_token->context;
			++this_token;
			if (this_token == token_list.end() || this_token->type != Colon)
			{
				cout << "[error] expect a \':\' this token: " << tmp.context << endl;
				return false;
			}
			++this_token;
			if (this_token == token_list.end() || (this_token->type != TokString && this_token->type != LeftBrace))
			{
				cout << "[error] expect a string or object after this token: " << tmp.context << endl;
				return false;
			}
			switch (this_token->type)
			{
			// string must get a child typed string
			case TokString:
				tmp.type = NodeString;
				--this_token;
				tmp.children.push_back(node_gen());
				break;
			// object get a return type object so it's children list must set to the same as return object
			case LeftBrace:
				tmp.type = NodeObj;
				--this_token;
				tmp.children = node_gen().children;
				break;
			}
			// if get error type ,parse failed
			if (tmp.children.back().type == ErrorType)
				return false;
			root.children.push_back(tmp);
			++this_token;
			if (this_token->type == RightBrace)
				--this_token;
			else if (this_token->type != Comma)
			{
				cout << "[error] expect a \',\' here." << endl;
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n, m;
	resource.clear();
	token_list.clear();
	ifstream fin("input");
	if (fin.fail())
	{
		cout << "Open file failed." << endl;
		return 0;
	}
	fin >> n >> m;
	getline(fin, temp_string); // 避免回车
	for (int i = 0; i < n; ++i)
	{
		getline(fin, temp_string);
		for (int j = 0; j < temp_string.length(); ++j)
			resource.push_back(temp_string[j]);
	}
	if (!lexer())
	{
		cout << "[lexer] error occurred,stop." << endl;
		return 0;
	}
	if (!parse())
	{
		cout << "[parse] error occurred,stop." << endl;
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		getline(fin, temp_string);
		str_search_list.clear();
		string t = "";
		for (int j = 0; j < temp_string.length(); ++j)
		{
			if (temp_string[j] != '.')
				t += temp_string[j];
			else
			{
				str_search_list.push_back(t);
				t = "";
			}
		}
		str_search_list.push_back(t);
		root.root_search();
	}
	return 0;
}