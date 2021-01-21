#include <iostream> //ketabkhaneh

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <bits/stdc++.h> // ketabkhaneh baraye dastoor power (tavan)
using namespace std;
//using counter to print all possible sub-sequences

void PrintAllSubsequences(int array[], int N,int size,int m )
{
    
    unsigned int set_size = pow(2, N) - 1 ;  //ba estefadeh az ketabkhaneh bits/stdc++.h mitavan  tedad kol ozvehaye arraye ra moshkhas kard
    
    int sum[60]={0};   //peyda kardan majmmo zirarraye
    int count=0;       // tedad halati keh barabar saize jabeh ha hast
    int a[60][60]={0}; // moshkhas kardan ashyaee keh kenar ham hastand
    for (int i = 1; i < set_size; i++) // halgheh baraye kol ozvhe
    {
        //printing subsequence
        
        for (int j = 0; j <= N; j++) // halgheh todarto baraye peyda kardan kol halat 
        {
            if(i & (1<<j)) // shift dadn j 
            {
            
              
               sum[i]+=array[j]; //yaftan majmoo iv tabagheh az ashya
                a[i][j]=array[j]; // dar arraye digari migozareem
            }
        }
        if(sum[i]==size)   // agar sum == sayze jabeh 
           {
               	count++;   // tedad halat ra moshkhas kon.
               	 
	    	}
    
    }
    
	// halgheh todar to mesle fogh faght zamani keh andaze ashya tori gharar begirand keh jabeh ha ra kamel por konad va agar khasteem kamtar ya mosavi sayze jabeh bashad bayad sum[i]<=size konim
    for (int i = 1; i < set_size; i++)
    {
    	int l;
    	
    	if(sum[i]==size)
    	{
    	cout<<"\n";
        }
    	for ( l = 0; l<= N; l++)
      	{
		
         	if(sum[i]==size&&a[i][l]!=0)
         	{ 
	        	cout<<" "<<a[i][l]<<" ,";
	     	}	
    	}	
    }
    
    cout<<"\n\ total of status\t"<<count;                      //namayesh kol halati keh ashya mitanannd dashteh bashand keh andazeh anha barabar shdc jabeh bashad.
}
 
      //Main function
    int main()
    {
    
    int n;
    int m,size;
    cout<<"input number of elements Array\t";
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
	
    cout<<"input element of Array\tArraye["<<i<<"]  ";
    cin>>arr[i];
    cout<<"\n";
}
    
    cout<<"\nthe size of box:\t";
    cin>>size;
    cout<<"\nthe number of box:\t";
    cin>>m;
    cout << "\nAll subarraye is equal size of box are:\n";
    PrintAllSubsequences(arr, n,size,m);
    return 0;
}
