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

uint64_t criterio_multiplicacion(uint64_t llave)
{
    int a =  99371;
    int b = 5303;
    int c = 121151;
    return (a * llave) >> (c - b);
}
 




int main(){
    uint64_t sum = 0;
    string str = "hrub";
    int arr[str.length()];
    int prime = 221;
    for (int i = 0; i < str.length(); i++) { arr[i] = (int)str[i]; }
    sum = horner(arr, str.length(), 128);
    sum = criterio_multiplicacion(sum);
    cout << str << "  " << sum << '\n';
    cout << division(prime ,sum);
    return 0;
}


