#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
 
 
class Company{
	public:
	 ll offered_salary;
	 ll max_job;
	 ll job_given;
	 string str;
};
 
 
bool compare(Company a, Company b){
	return a.offered_salary> b.offered_salary;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m;
		cin>>m;
		
		vi min_salary(n);
		for(int i=0;i<n;i++){
			cin>>min_salary[i];
		}
		
		vector<Company> company(m);
		for(int i=0;i<m;i++){
			cin>>company[i].offered_salary>>company[i].max_job;
			company[i].job_given=0;
		}
		
		string quali[n];
		for(int i=0;i<n;i++){
			cin>>quali[i];
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				company[i].str.push_back(quali[j][i]);
                        }
                 }       		
		
		
		
		sort(company.begin(), company.end(), compare);
		
		ll Total_salary=0, count=0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(company[j].str[i]=='1' && company[j].offered_salary>=min_salary[i] && company[j].max_job>0){
					company[j].max_job-=1;
					company[j].job_given=1;
				        count+=1;
				        Total_salary+=company[j].offered_salary;
				        break;
				}
			}
		}
		
		
		ll no_job=0;
		for(int i=0;i<m;i++){
			if(company[i].job_given==0){
				no_job++;
			}
		}
		
		cout<<count<<" "<<Total_salary<<" "<<no_job<<endl;
 
	}
	
return 0;
 
}
