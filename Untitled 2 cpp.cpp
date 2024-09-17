#include <iostream>
using namespace std;
class stacks {
private:
int top;
char stack[20];
public:
stacks() {
top = -1;
}
void push(char a) {
if (top < 20 - 1) {
stack[++top] = a;
} else {
cout << "Stack overflow" << endl;
}
}
char pop() {
if (top >= 0) {
return stack[top--];
} else {
cout << "Stack underflow" << endl;
return 0;
}
}
bool Empty() {
return (top == -1);
}
};
int main() {
char input[20];
stacks s;
cout << "Enter the string: ";
cin.getline(input, 20);
for (int i = 0; input[i] != 0; i++) {
s.push(input[i]);
}
cout << "Reversed string: ";
while (!s.Empty()) {
cout << s.pop();
}
cout << endl;
return 0;
}
