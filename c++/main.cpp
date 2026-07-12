#include <iostream>
#include <random> // <random> 라이브러리 포함
#include <chrono> // 시간 측정을 위한 헤더
#include <vector>

using namespace std;

int main() {
    const int n= 100000;
    vector<int> a(n, 0);

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(-20, 20);

    for (int i= 0; i < n; i++) {
        a[i]= distrib(gen);
    }

    cout << "size: " << n << endl;

    ///////////////////////////////////////////
    
    cout << "#############################" << endl << "O(L) time complexity      ##kadane algorithm + space complexity opt##" << endl;
    int m= -1000000000;

        
    auto start = chrono::high_resolution_clock::now();
    int c= a[0];
    for (int i= 1; i < n; i++) {
        c= max(c+a[i], a[i]);
        m= max(m, c);
    }
    cout << "res: " << m << " || ";
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration_ms = end - start;
    chrono::duration<double> duration_sec = end - start;

    cout << "time: " << duration_sec.count() << " sec\n";

    
    cout << "#############################" << endl << "O(L) time complexity      ##kadane algorithm##" << endl;
    m= -1000000000;

        
    start = chrono::high_resolution_clock::now();
    vector<int> dp(n, 0);
    for (int i= 1; i < n; i++) {
        dp[i]= max(dp[i-1]+a[i], a[i]);
        m= max(dp[i], m);
    }
    cout << "res: " << m << " || ";
    end = chrono::high_resolution_clock::now();
    
    duration_ms = end - start;
    duration_sec = end - start;

    cout << "time: " << duration_sec.count() << " sec\n";

    
    cout << "#############################" << endl << "O(L^2) time complexity##" << endl;
    m= -1000000000;

        
    start = chrono::high_resolution_clock::now();
    for (int i= 0; i < n; i++) {
        int s= 0;
        for (int j= i; j < n; j++) {
            s+= a[j];
            m= max(s, m);
        }
    }
    cout << "res: " << m << " || ";
    end = chrono::high_resolution_clock::now();
    
    duration_ms = end - start;
    duration_sec = end - start;

    cout << "time: " << duration_sec.count() << " sec\n";

    
    cout << "#############################" << endl << "O(L^3) time complexity##" << endl;
    m= -1000000000;

        
    start = chrono::high_resolution_clock::now();
    

    for (int i= 0; i < n; i++) {
        for (int j= i; j < n; j++) {
            int s= 0;
            for (int k= i; k < j+1; k++) {
                s += a[k];
            }
            m= max(m,s);
        }
    }

    cout << "res: " << m << " || ";
    end = chrono::high_resolution_clock::now();
    
    duration_ms = end - start;
    duration_sec = end - start;

    cout << "time: " << duration_sec.count() << " sec\n";
    cout << "#############################";

    return 0;
}
