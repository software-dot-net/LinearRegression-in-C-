#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

float vector_sumation(vector<float> vec){ 
    float summation = 0;
    for(int i=0;i<vec.size();i++){
        summation += vec[i];
    }
    return summation;
}

vector<float> vector_subtraction(vector<float> a, vector<float> b){ 
    vector<float> difference;
    if(a.size() != b.size()){
        cout << "invalid matrix \n";
    }
    else{
        for(int i=0;i<a.size();i++){
           difference.push_back(a[i] - b[i]);
        }
    }
    return difference;
}

vector<float> dot1d(vector<float> a,vector<float> b){ 
    vector<float> product;
    if(a.size() != b.size()){
        cout << "invalid vectors \n";
    }
    else{
        for(int i=0;i<a.size();i++){
            product.push_back(a[i] * b[i]);
        }
    }
    return product;
}

vector<vector<int>> dot2d(vector<vector<int>> a,vector<vector<int>> b){ 
    vector<vector<int>> product;
    if(a.size() != b[0].size()){
        cout << "invalid matrix \n";
    }
    else{
        for(int i=0;i<a.size();i++){
            vector<int> temp;
            for(int j=0;j<b[0].size();j++){
                int sum = 0;
                for(int k=0;k<b.size();k++){
                    sum += a[i][k] * b[k][j];
                }
                temp.push_back(sum);
            }
            product.push_back(temp);
        }
    }
    return product;
}

vector<float> scalar_dot_vector(vector<float> vec,int c){ 
    for(int i=0;i<vec.size();i++){
        vec[i] *= c;
    }
    return vec;
}

vector<float> scalar_add_vector(vector<float> vec,int c){ 
    for(int i=0;i<vec.size();i++){
        vec[i] += c;
    }
    return vec;
}

vector<float> LinearRegression(vector<float> X,vector<float> Y,float lr,int epochs){ 
    vector<float> coefficients,y_hat;
    int n = X.size();
    float c = 0, m = 0,D_m = 0,D_c = 0;
    if(X.size() != Y.size()) cout << "invalid vector \n";
    else{
        float k = -(float)2/n;
        for(int i=0;i<epochs;i++){
            y_hat = scalar_add_vector(scalar_dot_vector(X,m),c);
            D_m = k * vector_sumation(dot1d(X,vector_subtraction(Y,y_hat)));
            D_c = k * vector_sumation(vector_subtraction(Y,y_hat));
            m = m - lr * D_m;
            c = c - lr * D_c;
        }
        coefficients.push_back(m);
        coefficients.push_back(c);
    }
    return coefficients;
}

float predict(vector<float> coefficients,int x){
    float m = coefficients[0] , c = coefficients[1];
    float y_hat = m * x + c;
    return y_hat;
}


int main(){


    vector<float> X = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<float> Y = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
    vector<float> trained = LinearRegression(X,Y,0.00001,1000);
    cout << "coefficients :: " << trained[0] << " " << trained[1] << endl;
    cout << "prediction :: " << predict(trained,102) << endl;


    return 0;
}

