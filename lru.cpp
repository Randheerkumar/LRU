#include<iostream>
#include<queue>

using namespace std;
int get(int key,int arr[],int data[],int time[]);
void set(int ,int,int arr[],int data[],int time[]);
void delet(int,int arr[],int data[]);
int min(int time[]);

int capacity=1,last=1;
queue<int> s;
int main(){
	
	int key,data,ans;
	char a;
	cout<<"enter capacity (maximum size)\n";
	cin>>capacity;
	int hashTable[capacity],value[capacity],time[capacity]={0};
	for(int i=0; i<capacity; i++)
		hashTable[i]=-1;

	 cout<<"please enter your choice\n";
                cout<<"g: for get\ns: for set\ne: for exit\n" ;
                while(cin>>a){
                switch(a){
                	case 's':cout<<"enter the key and elment u want to insert\n";
                             cin>>key>>data;
                             set(key,data,hashTable,value,time);
                	         break;
                	case 'g':cout<<"enter the key for searching \n";
                             cin>>key;
                             ans=get(key,hashTable,value,time);
                             cout<<ans<<"\n";
                	         break;
                	case 'e': return 0;
                	default : cout<<"wrong choice , enter agian\n";
                }
                cout<<"enter again\n";
            }

}
int hash(int key){
	return (key%capacity);
}

void set(int key, int value,int arr[], int data[],int time[]){
    
	int prob,res;
	prob=hash(key);
	int count=0;
    while(arr[prob]!= (-1 ) && arr[prob]!= -2){
    	prob=(prob+1)%capacity;
    	count++;
    	if(count>capacity){
    		count=0;
                res=min(time);
                res=arr[res];
    		delet(res,arr,data);
    	}
    }
    arr[prob]=key;
    data[prob]=value;
    time[prob]=time[last]-1;
    last=prob;

}

int get(int key,int arr[],int data[],int time[]){
	int prob;
	int count=0;
	prob=hash(key);
    while(arr[prob]!=key){
    	prob=(prob+1)%capacity;
    	count++;
    	if(count>capacity){
    		return -1;
    	}
    }
     time[prob]=time[last]-1;
    last=prob;
    return(data[prob]);
 }

 void delet(int key,int arr[],int data[]){
 	int prob;
	int count=0;
	prob=hash(key);
    while(arr[prob]!=key){
    	prob=(prob+1)%capacity;
    	count++;
    	if(count>capacity){
    		cout<<"elment is already not present\n";
    		return;
    	}
    }
    arr[prob]=-2;
    //set(key,value,hashTable,value);

}
int min(int time[]){
      int max=-1000,i=0,index;
         for(i=0; i<capacity; i++){
         if(max<time[i] && time[i]!=0)
          {
           max=time[i];
           index=i;
     }
}
 return index;

}







