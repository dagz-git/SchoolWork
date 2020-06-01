#include<iostream> 
#include<string> 
#include<cmath> 
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
    if(n ==1){
        return n+666666;
    }
    uint64_t result = poly[0];
    for (int i=1; i<n; i++) 
        result = (result*x )+ poly[i]; 
  
    return result; 
} 

uint64_t division(uint64_t m, uint64_t k){
    return k % m;
}

uint64_t criterio_multiplicacion(uint64_t llave)
{
    long a = 95373766262;//big number
    long w = 34359738368; //2 close
    long m = 14273320331;//prime 2^n-1
    return (a * llave) >> (w - m);
}

uint64_t fibo(uint64_t k ){
    float phi = (5/3);
    uint64_t b = pow(2,43);
    uint64_t x = (b/phi);
    return (k * x) >> 16;

}
 
int main(){
    uint64_t sum = 0;
    string str = "p";
    int arr[str.length()];
    int prime = 2389723894;
    for (int i = 0; i < str.length(); i++) { arr[i] = (int)str[i]; }
    sum = fibo(criterio_multiplicacion(division(prime, horner(arr, str.length(), 1124))));
    cout << str << "  " << sum << '\n';
    return 0;
}