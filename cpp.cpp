#include <iostream>
#include <list>
#include <string>

bool checkIntegrity(const char* test, int size);

using namespace std;
class lifo{
    private:
        list<int> queue;
        int len;

    public:
        lifo(): len(0) {}

        void push(int x){
            queue.push_front(x);
            len++;
        }

        void pop(){
            if(len>0){
                queue.pop_front();
                len--;
            } else {
                throw "Tried to pop empty list";
            }
        }

        int read(){
            if(len>0){
                return queue.front();
            } else {
                throw "Tried to read empty list";
            }
        }

        bool Contains(int x){
            for (int a: queue){
                if (a == x) return true;
            }
            return false;
        }

        void Print(){
            for(int a: queue){
                cout << a << " ";
            }
            cout << endl;
        }

        void PushLessValue(int x){
            if(len>0){
                if(queue.front() > x){
                    push(x);
                }
            } else {
                throw "Tried to push with comparison to empty list";
            }
        }

        void PushUnique(int x){
            if(len>0){
                if(!Contains(x)){
                    push(x);
                }
            } else {
                throw "Tried to push with comparison to empty list";
            }
        }
};

int main(){
    lifo stack;
    int size = 15;
    char* test = new char[size];

    test = "{(5-[3+<9>])-4}";
    cout << ((checkIntegrity(test, size)) ? "True": "False") << endl;

    test = "{(>5-<[3+)9]-4}";
    cout << ((checkIntegrity(test, size)) ? "True": "False") << endl;
}

bool checkIntegrity(const char* test, int size){
    lifo stack;
    for(int i = 0; i < size; i++){
        switch (test[i]){
            case '{':
                stack.push(1);
                break;
            case '(':
                stack.push(2);
                break;
            case '[':
                stack.push(3);
                break;
            case '<':
                stack.push(4);
                break;
            case '>':
                if(stack.read() == 4)stack.pop();
                else return false;
                break;
            case ']':
                if(stack.read() == 3)stack.pop();
                else return false;
                break;
            case ')':
                if(stack.read() == 2)stack.pop();
                else return false;
                break;
            case '}':
                if(stack.read() == 1)stack.pop();
                else return false;
                break;
            default:
                break;
        }
    }
    return true;
}