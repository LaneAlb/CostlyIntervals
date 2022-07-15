#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'costlyIntervals' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY A
 */

vector<int> costlyIntervals(int n, int k, vector<int> A) {
    // Return a list of length n consisting of the answers
    // cost(l,r) = ( OR(l,r) - AND(l,r) - [(MAX(l,r)-MIN(l,r)] )
    // c = ( (l | r) - (l & r) - [(MAX(l,r)-MIN(l,r)]) 
    // [size(r-l-1)]
    int max = 0, min = 0, bor, band;
    int length = A.size();
    vector<int> r(length, -1); // [-1...-1]
    for(int s = 0; s < length; s++){
        for(int r = s+1; r < length; r++){
            if( (r-s) == 1){continue;} // skip subarrays of form [N]; s=N=r
            cout << "Subarray: " << s << r << endl;
            cout << "[";
            max = A[s]; // maximum value
            min = A[s]; // minimum value
            bor = A[s]; // bitwise OR
            band= A[s]; // bitwise AND
            for(int l = s; l < r; l++){
                // inside subarray A(l, r)
                cout << A[l] << ",";
                if(max < A[l]){max = A[l];} // get max
                if(min > A[l]){min = A[l];} // get min
                bor  = (bor | A[l]);
                band = (band & A[l]);
            }
            cout << "]" << endl 
            << "Max: " << max << endl 
            << "Min: " << min << endl
            << "OR: "  << bor << endl 
            << "AND: " << band << endl
            << "COST: "<< (bor - band - (max - min)) << endl;
        }
    }
    return r;
}


/* BELOW is Hackerrank provided info */
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    vector<int> result = costlyIntervals(n, k, A);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
