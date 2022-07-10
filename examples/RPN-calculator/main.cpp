#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

enum TokenKind {
    Add,
    Sub,
    Mul,
    Div,
    Num,
    Error,
};

struct Token {
    TokenKind kind;
    int data;

    Token(TokenKind kind) : kind(kind) {}
    Token(TokenKind kind, int data) : kind(kind), data(data) {}
};

bool is_whitespace(char c) { return c == ' ' || c == '\n' || c == '\t'; }

bool is_number(char c) { return '0' <= c && c <= '9'; }

struct Lexer {
    string src;
    size_t cursor;

    Lexer(string src) : src(src), cursor(0) {}

    char peek_char() { return src[cursor]; }
    void advance_cursor() {
        if(!is_eof()) {
            cursor += 1;
        }
    }

    bool is_eof() { return cursor >= src.length(); }

    void skip_whitespace() {
        while(is_whitespace(peek_char())) {
            cursor += 1;
        }
    }

    Token advance_token() {
        skip_whitespace();

        char first_char = peek_char();
        advance_cursor();
        switch(first_char) {
        case '+':
            return Token(TokenKind::Add);
        case '-':
            return Token(TokenKind::Sub);
        case '*':
            return Token(TokenKind::Mul);
        case '/':
            return Token(TokenKind::Div);
        default:
            if(is_number(first_char)) {
                int data = number(first_char);
                return Token(TokenKind::Num, data);
            }

            return Token(TokenKind::Error);
        }
    }

    int number(char first_char) {
        string s = {first_char};
        while(1) {
            char c = peek_char();
            if(is_number(c)) {
                s.push_back(c);
                advance_cursor();
            } else {
                break;
            }
        }

        return stoi(s);
    }
};

ostream &operator<<(ostream &stream, const Token &t) {
    switch(t.kind) {
    case TokenKind::Add:
        stream << '+';
        break;
    case TokenKind::Sub:
        stream << '-';
        break;
    case TokenKind::Mul:
        stream << '*';
        break;
    case TokenKind::Div:
        stream << '/';
        break;
    case TokenKind::Num:
        stream << t.data;
        break;
    case TokenKind::Error:
        stream << "Err";
        break;
    }
    return stream;
}

vector<Token> lex(const string &src) {
    vector<Token> tokens;
    Lexer lexer(src);
    while(!lexer.is_eof()) {
        Token t = lexer.advance_token();
        if(t.kind == TokenKind::Error) {
            return tokens;
        }
        tokens.push_back(t);
    }

    return tokens;
}

int eval(const vector<Token> &tokens) {
    stack<int> s;
    for(const auto t : tokens) {
        if(t.kind == TokenKind::Num) {
            s.push(t.data);
        } else {
            int left = s.top();
            s.pop();
            int right = s.top();
            s.pop();

            int result;
            switch(t.kind) {
            case TokenKind::Add:
                result = left + right;
                break;
            case TokenKind::Sub:
                result = left - right;
                break;
            case TokenKind::Mul:
                result = left * right;
                break;
            case TokenKind::Div:
                result = left / right;
                break;
            default:
                break;
            }
            s.push(result);
        }
    }

    return s.top();
}

int main(int argc, char *argv[]) {
    ifstream ifs(argv[1]);
    string input((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    vector<Token> tokens = lex(input);
    for(const auto t : tokens) {
        cout << t << " ";
    }
    cout << endl;

    cout << "= " << eval(tokens) << endl;
}