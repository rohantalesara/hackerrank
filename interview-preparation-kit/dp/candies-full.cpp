#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    int prevstreak=1,streak=1,inc,previnc;
    long totsum=0,currsum=0;

    if(n>=2){
        if(arr[0]<arr[1]){
            inc=1;
            previnc=1;
        }
        else{
            inc=0;
            previnc=0;
        }
    }
    else{
        return 1;
    }

    int start=1;
    for(int i=0;i<n-1;i++){
        if(inc==1){
            if(arr[i]<arr[i+1]){
                currsum+=streak;
                streak+=1;
            }
            else{
                currsum+=streak;
                totsum+=currsum;
                currsum=0;
                prevstreak=streak;
                streak=1;
                previnc=1;

                if(i!=n-2 && (arr[i+1]>arr[i+2])){
                    inc=0;
                }
            }
        }
        else if(inc==0){
            if(arr[i]>=arr[i+1]){
                currsum+=streak;
                streak+=1;
            }
            else{
                currsum+=streak;
                totsum+=currsum;
                currsum=0;
                if(previnc==1 && streak>prevstreak){
                    totsum+=streak-prevstreak;
                }
                prevstreak=streak;
                streak=1;
                previnc=0;
                if(i!=n-2 && (arr[i+1]<arr[i+2])){
                    streak=2;
                    inc=1;
                }
            }
        }
    }
    currsum+=streak;
    return totsum+currsum;
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
