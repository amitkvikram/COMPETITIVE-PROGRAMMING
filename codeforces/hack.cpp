#include <bits/stdc++.h>
using namespace std;
vector <long long int> vec;
long long int n;


void arrange (long long int *a ,long long int left ,long long int right,long long int r , long long int * indices )
{

   //    cout << r << endl;
   if (left <= right)
   {
       long long int mid = (left + right) / 2;
       vec[r] = a[mid]; 
       indices[mid] = r;
       arrange(a, left, mid - 1, 2 * r , indices);
       arrange(a, mid + 1, right, 2 * r + 1 , indices);
    }
       
}

long long int binarySearch (vector <pair <long long int ,long long  int >> &vec ,long long  int  left ,long long int right , long long int x) 
{
    if (left > right)
    return -1;

    long long int mid = (left + right)/2;
    if (vec[mid].first ==x )
    return mid;

    if (x > vec[mid].first )
    return binarySearch (vec , mid+1 , right , x);

    if (x < vec[mid].first)
    return binarySearch (vec , left , mid-1 , x);
}

void printTree (int r ,  int offset)
	{
        
		if (2*r+1 <= 2*n)
			printTree (2 * r + 1, offset + 1);

		for (int i =0  ; i < offset ; i++)
			cout << "\t";
		cout << vec[r] << endl << endl ;

		if (2 * r <= 2*n)
			printTree (2 * r , offset+1);

	}

int main ()
{
    long long int test;
    cin >> test;
    while (test--)
    {
        vec.clear();
        long long int  q;
        cin >> n >> q;
        long long int a[n+10];
        long long int indices[n+10];
        for (long long int i= 0 ; i < n; i++)
            cin >> a[i];
        
        vec.assign (2*n+1, 0);
        cout << endl;
        arrange(a, 0, n - 1, 1, indices);
        for (int i = 0; i < n+1; i++){
            cout << vec[i] << ' ';
        }

        cout << endl;

        vector<pair<long long int, long long int>> elements;
        for (long long int i= 0 ; i < n ; i++)
        elements.push_back (make_pair (a[i] , indices[i]));

        sort (elements.begin() , elements.end());
        printTree(1, 0);

        while (q--)
        {
            long long int x;
            cin >> x;
            long long int index = binarySearch (elements , 0 , n-1 , x );

            vector<pair <long long int ,long long int >> path;
            long long int posn = elements[index].second;
            path.push_back(make_pair(posn, -1));
            long long int child = posn;
            posn = posn / 2;
            while (posn >= 1)
            {
                long long int temp = -1;          //0 is for the left child 
                if (child == 2*posn)
                    temp = 0;

                else if (child == 2*posn + 1)       //1 is for the right child
                    temp = 1;

                path.push_back (make_pair (posn , temp));
                child = posn;
                posn = posn / 2;

                
            }

            long long int totalLesser = index;
            long long int totalGreater = n - index - 1;

            //for (int i =0 ; i < path.size() ; i++)
            //cout << path[i].first  << " -" << path[i].second  << endl;;
            //cout << endl;

            vector <pair <long long int ,long long int>> check;
            //1 stands for the false
            for (long long int i= 1 ; i < path.size() ; i++ )
            {
                if ( path[i].second == 0 )
                {
                    if ( vec[path[i].first] < x )
                    check.push_back (make_pair (1 , 0));
                    else
                    check.push_back (make_pair (0 , 0));
                }
                if (path[i].second == 1)
                {
                    if (vec[path[i].first] > x )
                    check.push_back(make_pair (1 , 1));
                    else
                    check.push_back(make_pair (0 , 1) );

                }
            }

            //for (int i =0 ; i < check.size() ; i++)
            //cout << check[i].first << " " << check[i].second << endl;
            //cout << endl << endl;

            long long int realAns = -2;
            long long int greaterRequired = 0;
            long long int lesserRequired = 0;
            long long int cnt_less = 0;
            long long int cnt_greater = 0;
            for (long long int i = 0; i < check.size(); i++)
            {
                if (check[i].second == 1){
                    if(check[i].first == 1) lesserRequired++;
                    else
                        cnt_less++;
                }

                else if (check[i].second == 0){
                    if(check[i].first == 1)
                        greaterRequired++;
                    else
                        cnt_greater++;
                }
            }

            //cout << greaterRequired << " greaterRequired" << endl;
            //cout << totalGreater << " totalGreater" << endl;
 
            if (lesserRequired == 0 && greaterRequired == 0 )
            realAns = 0;
            else if (lesserRequired + cnt_less> totalLesser || greaterRequired + cnt_greater> totalGreater)
            realAns = -1;
            else{
                long long int b = max (greaterRequired , lesserRequired);
                realAns = b;

            }

            cout << realAns << endl;

        }
    }
    return 0;
}