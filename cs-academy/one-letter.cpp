/*
9
inside
socks
after
wait
element
start
olives
mushroom
envelope

OUT: aaacdeeeh
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector <string> words;

char smallestChar(string word, int n){
    char min = 'z';
 
    for (int i=0; i<n-1; i++)   
        if (word[i] < min)
            min = word[i];   
 
    return min;
}

string sortString(string &str){
    sort(str.begin(), str.end());
    return str;
}

int main(void){
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string word;
        cin >> word;
        words.push_back(word);
    }

    string answer;
    for (int i = 0; i < N; i++){
        char ch = smallestChar(words.back(), words.back().size());
        answer.push_back(ch);
        words.pop_back();
    }

    cout << "\n" << sortString(answer);
    return 0;
}