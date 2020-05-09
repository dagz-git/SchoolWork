#include<iostream> 
#include<string> 
using namespace std;



int juampy_hash(string s){
    int k = 69;
    int key =0;

    for (int i = 0; i < s.length(); i++)
    {
        key += (k * key)+ (int)s[i];
    }
    return key;

}

uint64_t horner(int poly[], int n, int x) 
{ 
    uint64_t result = poly[0];
    for (int i=1; i<n; i++) 
        result = (result*x )+ poly[i]; 
  
    return result; 
} 

uint64_t division(int m, uint64_t k){
    return k % m;
}


int main(){
    uint64_t sum = 0;
    string str = "CLRS";
    int arr[str.length()];
    
    for (int i = 0; i < str.length(); i++)
    {
        arr[i] = (int)str[i];
    }
    
    
    sum = horner(arr, str.length(), 128);

    cout << str << "  " << sum << '\n';
    cout << division(7,sum);
    return 0;
}


