#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<vector<ll>> vvi;
const ll inf = LLONG_MAX;
int n;
ll total = LLONG_MAX;

class return_type{
    public:
    ll a;
    bool check;
};

bool isvalid(int i, int N){
    return i>=0 && i<N;
}

return_type fill_C(int ind, vl &A, vi &B, vi &C, vvi &S, int curr_sum, int curr_sign, int prev_sign){
    //End Recursion
    // if(ind>=n) return 0;
    // cout<<"CALL: "<<"ind = "<<ind<<" Current Sum = "<<curr_sum<<" C = "<<C[ind];
    // cout<<" Prev_sign = "<<prev_sign<<" B = "<<B[ind]<<endl;

    //Case1: If current number can not be negative
    if(B[ind] == 1){
        C[ind] = 1;     //C will be 1

        //if ind is first index
        if(ind == 0){
            //if no need of changing sign
            if(A[ind] > A[ind + 1]){
                return_type temp =fill_C(ind +1 , A, B, C, S, curr_sum + A[ind], -1, -1);
                S[ind][0] = temp.a + A[ind];
                if(curr_sum + S[ind][0] <= total){
                    total = curr_sum + S[ind][0];
                }
                return return_type{S[ind][0], false};
            }
            //need of changing sign(of ind +1)
            else{
                return_type temp = fill_C(ind +1, A, B, C, S, curr_sum + A[ind], 1, -1);
                S[ind][0] = temp.a + A[ind];
                if(curr_sum + S[ind][0] <= total){
                    total = curr_sum + S[ind][0];
                }
                return return_type{S[ind][0], false};
            }
        }

        //if ind is last index
        else if(ind == n - 1){
            //if no need of changing sign
            if(A[ind] > A[ind - 1]){
                S[ind][0] = A[ind];
                if(curr_sum + A[ind] <= total){
                    total = curr_sum + A[ind];
                }
                return return_type{S[ind][0], false};
            }
            //need of changing sign
            else{
                C[ind - 1] = 1;   //necessary to change sign of ind - 1 if its negative.
                S[ind][0] = A[ind];
                if(curr_sum + 2* A[ind - 1] + A[ind] <= total){
                    total = curr_sum + 2* A[ind - 1] + A[ind];
                }
                return return_type{S[ind][0], true};
            }
        }

        //if ind is b/w 0 and n-1
        else{
            //if sign of previous element was not changed
            if(prev_sign == -1){
                //if previous element can never be negative
                if(B[ind - 1] == 1){
                    //if no need of changing sign
                    if(A[ind] > A[ind + 1]){
                        return_type temp =  fill_C(ind+1, A, B, C, S, curr_sum + A[ind], -1, -1);
                        S[ind][0] = A[ind] + temp.a;
                        if(curr_sum + S[ind][0] <= total){
                            total = curr_sum + S[ind][0];
                        }
                        return return_type{S[ind][0], false};
                    }
                    //if need of changing sign(here compulsory because previous element is alsways positive)
                    else{
                        return_type temp = fill_C(ind + 1, A, B, C, S,curr_sum + A[ind], 1, -1);
                        S[ind][0] = A[ind] + temp.a;
                        if(curr_sum + S[ind][0] <= total){
                            C[ind + 1] = 1;
                            total = curr_sum + S[ind][0];
                        }
                        return return_type{S[ind][0], false};
                    }

                }
                //If previous element can be negative
                else{
                    //if no need of changing sign
                    if(A[ind] > A[ind - 1] + A[ind + 1]){
                        return_type temp = fill_C(ind +1, A, B, C, S, curr_sum + A[ind], -1, -1);
                        S[ind][0] = temp.a + A[ind];
                        if(curr_sum + S[ind][0] <= total){
                            C[ind -1] = B[ind - 1];
                            total = curr_sum + S[ind][0];
                        }
                        return return_type{S[ind][0], false};
                    }
                    //if next element can not be negative
                    else if(B[ind + 1] == 1){
                        //no need of sign change(of prev element)
                        if(A[ind] > A[ind - 1]){
                            return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum + A[ind], -1, -1);
                            S[ind][0] = temp.a + A[ind];
                            if(curr_sum + S[ind][0] <= total){
                                C[ind -1] = B[ind - 1];
                                total = curr_sum + S[ind][0];
                            }
                            return return_type{S[ind][0], false};
                        }
                        //need of sign change(of prev element)
                        else{
                            return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum + A[ind], -1, -1);
                            S[ind][0] = temp.a + A[ind];
                            if(curr_sum + S[ind][0] + 2*A[ind - 1] <= total){
                                C[ind -1] = 1;
                                total = curr_sum + S[ind][0] + 2*A[ind - 1];
                            }

                            return return_type{S[ind][0], true};
                        }
                    }
                    //if can be need of changing sign and next element can be negative(prev can be neg)
                    else{
                        //Change sign of previous index(ind - 1)
                        return_type temp1 = fill_C(ind +1, A, B, C, S, curr_sum + 2*A[ind - 1] + A[ind], -1, -1);
                        //change sign of next index(ind + 1)
                        return_type temp2 = fill_C(ind + 1, A, B, C, S, curr_sum + A[ind], 1, -1);
                        //Compare which one of the above is efficient
                        
                        //if first one is efficient
                        if(curr_sum + 2*A[ind - 1] + temp1.a < curr_sum + temp2.a){
                            S[ind][0] = A[ind] + temp1.a;
                            return return_type{S[ind][0], true};
                        }
                        //if second one is efficient
                        else{
                            S[ind][0] = A[ind] + temp2.a;
                            return return_type{S[ind][0], false};
                        }
                        //BUG START
                        if(min(2*A[ind - 1] + A[ind] + temp1.a, A[ind] + temp2.a) <= total - curr_sum){
                            //if first one is efficient
                            if(curr_sum + 2*A[ind - 1] + temp1.a < curr_sum + temp2.a){
                                C[ind - 1] = 1;
                                total = curr_sum + 2*A[ind - 1] + temp1.a + A[ind];
                            }
                            //if second one is efficient
                            else{
                                C[ind - 1] = -1;
                                total = curr_sum + temp2.a + A[ind];
                            }
                        }
                        //BUG END
                    }
                }
            }
            //if sign of previous element was changed
            else{
                //It is obvious that previous element can be negative
                return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum + A[ind], -1, -1);
                S[ind][0] = temp.a + A[ind];
                if(curr_sum + S[ind][0] <= total){
                    C[ind -1] = 1;
                    total = curr_sum + S[ind][0];
                }
                return return_type{S[ind][0], false};
            }
        }
        //
    }

    //Case2: If current number can be negative(B[ind] == -1)
    else{
        //if ind is first index
        if(ind == 0){
            return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum - A[ind], -1, -1);
            //next call says no need of changing size of current one
            if(temp.check == false){
                if(curr_sum + temp.a - A[ind] <= total){
                    C[ind] = -1;
                    total = curr_sum + temp.a - A[ind];
                }
            }
            //next call says change the size of current one
            else{
                if(curr_sum + temp.a <= total - A[ind]){
                    C[ind] = 1;
                    total = curr_sum + temp.a + A[ind];
                }
            }
            return return_type{S[ind][1] , false};
        }
        //if ind is last index
        else if(ind == n - 1){
            //If need to change sign for current ind
            if(curr_sign == 1){
                if(curr_sum <= total - A[ind]){
                    C[ind] = 1;
                    total = curr_sum + A[ind];
                }
                S[ind][0] = A[ind];
                return return_type{S[ind][0], false};
            }
            //if no need to change sign
            else{
                if(curr_sum - A[ind] <= total){
                    C[ind] = -1;
                    total = curr_sum - A[ind];
                }
                S[ind][1] = -A[ind];
                return return_type{S[ind][1], false};
            }
        }

        //if ind is b/w 0 and n - 1
        else{
            //if need for changing current sign
            if(curr_sign == 1){
                return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum + A[ind], -1, 1);
                if(curr_sum + temp.a <= total - A[ind]){
                    C[ind] = 1;
                    total = curr_sum + temp.a + A[ind];
                }
                S[ind][0] = temp.a + A[ind];
                return return_type{S[ind][0], false};
            }
            //if no need for changing current sign
            else{
                return_type temp = fill_C(ind + 1, A, B, C, S, curr_sum - A[ind], -1, -1);
                //next call says no need of changing size of current one
                if(temp.check == false){
                    S[ind][1] = temp.a - A[ind];
                    if(S[ind][1] + curr_sum <= total){
                        C[ind] = -1;
                        total = S[ind][1] + curr_sum;
                    }
                    return return_type{S[ind][1], false};
                }
                //if next call says change size of current one
                else{
                    S[ind][0] = temp.a + A[ind];
                    if(curr_sum + S[ind][0] <= total){
                        C[ind] = 1;
                        total = curr_sum + S[ind][0];
                    }
                    return return_type{S[ind][0], false};
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vl A(100001);
    vector<vector<ll> > S(100001, vector<ll>(2));
    vi B(100001), C(100001);
    while(t--){
        cin >> n;
        for (int i = 0; i <n; i++){
            cin >> A[i];
            A[i] = abs(A[i]);
        }

        for(int i = 0; i<n; i++){
            B[i] = 1;
            C[i] = 1;
        }

        for(int i = 0; i<n; i++){
            if((!isvalid(i - 1, n) || A[i-1] > A[i]) && (!isvalid(i + 1, n) || A[i + 1] > A[i])){
                B[i] = -1;
                C[i] = -1;
            }
        }


        // for(int i = 0;i<n; i++){
        //     cout<<B[i]*A[i]<<" ";
        // }

        // cout<<endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<2; j++){
                S[i][j] = inf;
            }
        }

        //Calculate C[i]
        total = LLONG_MAX;
        fill_C(0, A, B, C, S, 0, -1, -1);

        //Final print
        for(int i = 0; i<n; i++){
            if(C[i] == -1) cout<<-A[i]<<' ';
            else cout<<A[i]<<' ';
        }
        cout<<endl;
    }
}