#include<iostream> 
#include<string> 
#include<cmath> 
#include<fstream>
#include<bitset>
#include<iomanip>
using namespace std;

int juampy_hash(string s);
int hamming_distance(string str1 , string str2);
string bitflip(string str);
uint64_t horner(int poly[], int n, int x);
uint64_t division(uint64_t m, uint64_t k);
uint64_t criterio_multiplicacion(uint64_t llave);
uint64_t fibo(uint64_t k );
uint64_t magic(string str);
uint64_t keyconverter(uint64_t key);
uint64_t avalanche(uint64_t key, string func);

int main(){

    ifstream myFile;
    myFile.open("diccionario.csv");
    float counter = 0;

    long double unifmul = 0;
    long double  unifdiv = 0;
    long double uniffibo = 0;

    long double blizzard_mult =0;
    long double blizzard_div =0;
    long double blizzard_fibo =0;

    int m = 131072;
    int size = 105886;

    float* freqmult = new float[m];
    float* freqdiv = new float[m];
    float* freqfibo = new float[m];

    while(myFile.good()){
        string line;
        getline(myFile, line);
        line.pop_back();
 
        uint64_t value1 = criterio_multiplicacion(magic(line)) % m;
        uint64_t value2 = division(m, magic(line)) % m;
        uint64_t value3 = fibo(magic(line)) % m;
        
        freqmult[value1] += 1.0;
        freqdiv[value2] += 1.0;
        freqfibo[value3] += 1.0;

        counter += 1;
    }
    
    float denominador = (counter / 2 * m) * (counter + 2*m - 1);

    float numeradorMult = 0;
    float numeradorDiv = 0;
    float numeradorFibo = 0;

    for (int i = 0; i < counter - 1; i++)
    {
        numeradorMult += freqmult[i] * (freqmult[i] - 1) / 2;
        numeradorDiv += freqdiv[i] * (freqdiv[i] - 1) / 2;
        numeradorFibo += freqfibo[i] * (freqfibo[i] - 1) / 2;
        blizzard_mult += avalanche(freqmult[i],"mult");
        blizzard_div += avalanche(freqmult[i],"div");
        blizzard_fibo += avalanche(freqmult[i],"fibo");

    }

    long double one = 1;

    unifmul = one - (long double)(numeradorMult / denominador);
    unifdiv = one - (long double)(numeradorDiv / denominador);
    uniffibo = one - (long double)(numeradorFibo / denominador);

    cout << " " << endl;
    cout << "HUH, uniformidad multi: " << fixed << setprecision(24) << unifmul << endl;
    cout << "HUH, uniformidad division: " << fixed << setprecision(24) << unifdiv << endl;
    cout << "HUH, uniformidad fibo: " << fixed << setprecision(24) << uniffibo << endl;


    cout << "HUH, Avalancha multi: " <<   (blizzard_mult/size)<< endl;
    cout << "HUH, Avalancha division: "  << (blizzard_div/size) << endl;
    cout << "HUH, Avalancha fibo: "  << (blizzard_fibo / size) << endl;

    myFile.close();

    return 0;
}

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
    for (int i=1; i < n; i++) 
        result = (result * x) + poly[i]; 
  
    return result; 
} 

uint64_t division(uint64_t m, uint64_t k){
    return k % m;
}

uint64_t criterio_multiplicacion(uint64_t llave)
{
    long a = 92321;//big number
    long w = 242232; //2 close
    long m = 131072;//prime 2^n-1
    return (a * llave) >> (w - m);
}

uint64_t fibo(uint64_t k ){
    float phi = (5/3);
    uint64_t b = pow(2,17);
    uint64_t x = (b/phi);
    return (k * x) >> 32;

}

uint64_t magic(string str){
    
    uint64_t sum = 0;
    uint64_t sumdiv = 0;
    uint64_t summult = 0;
    uint64_t sumfibo = 0;

    int arr[str.length()];
    int prime = 221;
    for (int i = 0; i < str.length(); i++) { arr[i] = (int)str[i]; }
    sum = horner(arr, str.length(), 1124);
    //sumdiv = division(2389723894, sum);
    //summult = criterio_multiplicacion(sum);
    return sum;
    //sumfibo = fibo(sum);
    //cout << str << " multi: " << summult << " div: " << sumdiv << " fibo: " << sumfibo << endl;
}

string bitflip(string str){
   int r = rand()%str.length();
   if(str[r]=='0'){
       str[r] = '1';
    }
    else{
        str[r] ='0';
    }
    return str;

    
}

int hamming_distance(string str1 , string str2){
    int cont =0;
    for (size_t i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            cont++;
        }
    }
    return cont;
    
}

uint64_t avalanche(uint64_t key , string func){
     string x = bitset<64>(key).to_string();
     string y = bitflip(x);
     uint64_t x1;
     uint64_t y1;
     uint64_t bigchungus = stoull(y,0,2);
     
    if(func == "mult"){
         x1 = criterio_multiplicacion(key);
         y1 = criterio_multiplicacion(bigchungus);
    }
    else if(func == "div"){
         x1 = division(131072,key);
         y1 = division(131072,bigchungus);
    }
    else{
         x1 = fibo(key);
         y1 = fibo(bigchungus);
    }
     
     string x2 = bitset<64>(x1).to_string();
     string y2 = bitset<64>(y1).to_string();

     int juampy = hamming_distance(x2,y2);
    
     //cout << "Str1 " << x2 << "  Str2 :" << y2 << '\n';
     //cout << "Jaumpy : " << juampy;
     return juampy;


}

