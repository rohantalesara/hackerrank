//https://www.hackerrank.com/challenges/candies/problem?h_l=interview&h_r=next-challenge&h_v=zen&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming
#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=1;
    }
    long sum=0;
    int k;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            ans[i]=ans[i-1]+1;
        }
        else{
            if(ans[i-1]<=ans[i]){
                k=i;
                while((arr[k-1]>arr[k]) && (ans[k-1]<=ans[k])){
                    ans[k-1]++;
                    k--;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        sum+=ans[i];
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
