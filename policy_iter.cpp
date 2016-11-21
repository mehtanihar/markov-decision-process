#include<iostream>
#include<fstream>
#include<list>
#include<string>
using namespace std;

double abs(double x){
	
	if(x<0){return -1*x;}
	else{return x;}
	
}

double max1(double a, double b){
	if(a>b)return a;
	else return b;
	
}



void evaluate_policy(double V[],int S,list<double> R[100][100], list<double> T[100][100], double gamma, int policy[]){

	
	double error=0.2;
	double v;
	list<double>::iterator it1;
	list<double>::iterator it2;
	double R_val,T_val;
	while( error>0.0000000000000001){
		error=0;
	
		for(int i=0;i<S;i++){
			v=V[i];
			double sum=0;
			it1=R[i][policy[i]].begin();
			it2=T[i][policy[i]].begin();
			for(int j=0;j<S && it1!=R[i][policy[i]].end();j++){
				
				R_val=*it1;
				T_val=*it2;
				
				sum=sum+T_val*(R_val+gamma*V[j]);
				it1++;
				it2++;
				
			}
			V[i]=sum;
			error=max1(error,abs(v-V[i]));
			
			
		}
	}
		
}

bool policy_improve(double V[],int S, int A,list<double> R[100][100], list<double> T[100][100], int policy[],double gamma){
	
	bool policy_stable=true;
	double b;
	list<double>::iterator it1;
	list<double>::iterator it2;
	double R_val,T_val;
	
	for(int i=0;i<S;i++){
		
		b=policy[i];
		double max=0;
		double action=0;
		
		for(int j=0;j<A;j++){
			
			double sum=0;
			it1=R[i][j].begin();
			it2=T[i][j].begin();
			
			for(int k=0;k<S && it1!=R[i][j].end();k++){
				
				
				R_val=*it1;
				T_val=*it2;
				sum=sum+T_val*(R_val+gamma*V[k]);
				it1++;
				it2++;	
				
				
			}
			
			if(sum>max){max=sum;action=j;}
			
			
			
		}
		
		policy[i]=action;
		
		if(b!=policy[i]){policy_stable=false;}
		
		
		
		
	}
	
	
	return policy_stable;
	
	
	
	
}




int main(int argc, char *argv[]){

	char* s; 
	

	s=argv[1];

	
	
	int S,A;
	
 

	double gamma;
	double temp;
	

	
	ifstream myfile (s);
	
		  
		  myfile>>S; 
		  myfile>>A; 
		  
		  
		  list<double> R[100][100];
		  list<double> T[100][100];
		 
	
		  for(int i=0;i<S;i++){
			
			for(int j=0;j<A;j++){			
				
				for(int k=0;k<S;k++){
					
					myfile>>temp;
					
					R[i][j].push_back(temp);
					
					
					
					
				}
				
			}
			
		}
		
		  for(int i=0;i<S;i++){
			
			for(int j=0;j<A;j++){			
				
				for(int k=0;k<S;k++){
					
					myfile>>temp;
					T[i][j].push_back(temp);
					
					
				}
				
			}
			
		}
		
		myfile>>gamma;
		  
		  

	

 
	
	
	
	double V[S];
	int policy[S];
	//double V_prev[S];
	
	for(int i=0;i<S;i++){
		
		V[i]=0; //V_prev[i]=0;
		policy[i]=i;
		
	}
	
	
	bool policy_stable=false;
	
	while(!policy_stable){
		
		evaluate_policy(V,S,R,T,gamma,policy);
		policy_stable=policy_improve(V,S,A,R,T,policy,gamma);
		
	}
	evaluate_policy(V,S,R,T,gamma,policy);
	
	
	for(int i=0;i<S;i++){
			
			cout<<V[i]<<" "<<policy[i]<<endl;
			
	}
	
	







}
