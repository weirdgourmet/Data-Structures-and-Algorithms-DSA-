
#include<iostream>
using namespace std;
class game {
public :
	int num,str,i,rol;
	int roll[50],c[50],b[50],un[50],inter[50],onb[50],onc[50];
	void ini();
	void both();
	void uni();
	void oc();
	void ob();
	void input();
	void output();



};
	void game ::ini(){
		for(i=1;i<=50;i++){
			roll[i]=i;
			c[i]=0;
			b[i]=0;
		}
	}
    void game ::both() {
    	for(i=1;i<=str;i++){
    		if((c[i]==1)&&(b[i]==1)){
    			inter[i]=1;
    		}
    		else{
    			inter[i]=0;
    		}
    	}
    }
    void game ::uni() {
     	for(i=1;i<=str;i++){
     		if((c[i]==1)||(b[i]==1)){
     			un[i]=1;
     		}
     		else{
     			un[i]=0;
     		}
     	}
     }
    void game::ob(){
    	for(i=0;i<=str;i++){
    		if((b[i]==1)&&(inter[i]==0)){
    			onb[i]=1;
    		}
    		else onb[i]=0;
    	}
    }
    void game::oc(){
       	for(i=0;i<=str;i++){
       		if((c[i]==1)&&(inter[i]==0)){
       			onc[i]=1;
       		}
       		else onc[i]=0;
       	}
       }
	void game :: input(){

		cout<<"Enter Roll Number  ";
		cin>>rol;
		for(i=0;i<10;++i){
			if(rol==0){
				cout<<" invalid input ";
				break;
			}
			else{
				if(rol>num){
					cout<<" invalid input ";
					break;
				}
				else{
					if(i==rol){
						roll[i]=rol;
						cout<<"If you play cricket enter '1' if not enter '0' ";
						cin>>c[i];
						cout<<"If you play badminton enter '1' if not enter '0' ";
						cin>>b[i];
					}
				}
			}
		}


		i=0;
	}
	void game ::output(){
			for(i=1;i<=num;i++){
				if(roll[i]!=0){
					if(roll[i]!=0){
						cout<<"\nRoll number"<<roll[i];
					}
					if(c[i]!=0){
						cout<<" \nCricket ";
					}
					if(b[i]!=0){
						cout<<"\nBadminton";
					}
				}
			}

			cout<<"\n Students playing both games are ";
			for(i=1;i<=str;i++){
				if(inter[i]==1){
					cout<<"ROLL NO "<<roll[i];
				}
			}
			cout<<"\n Students playing either cricket or badminton are";
			for(i=1;i<=str;i++){
				if(un[i]==1){
					cout<<"\n ROLL NO "<<roll[i];
				}
			}
			cout<<"\n Students playing only cricket are  ";
			for(i=1;i<=str;i++){
				if(onc[i]==1){
					cout<<"\n ROLL NO "<<roll[i];
				}
			}
			cout<<"\n Students playing only badminton are  ";
			for(i=1;i<=str;i++){
				if(onb[i]==1){
					cout<<"\n ROLL NO "<<roll[i];
				}
			}
			cout<<"\n Students playing neither cricket nor badminton are  ";
			for(i=1;i<=str;i++){
				if(un[i]==0){
					cout<<"\n ROLL NO "<<roll[i];
				}
			}
	}
	int main(){
		int j;
		game d;
		d.ini();

		cout<<"Enter Strength of Division  ";
		cin>>d.str;
		cout<<"Enter Number of inputs ";
		cin>>d.num;
		if(d.str<d.num){
			cout<<"invalid operation";
		}
		else{

			for(j=0;j<d.num;++j){
				d.input();
			}
			d.both();
			d.uni();
			d.oc();
			d.ob();
			d.output();
		}

		return 0;
	}



