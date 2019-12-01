import java.util.Arrays;
import java.util.Scanner;
 
public class StairMax {

	public static void main(String[] args){
	int input = sc.netxInt(); 	  // 계단의수
	int value[] = new int[input+1]; // 계단의 점수값을 담을 배열
	int dp[] = new int[input+1];     // 각각의 계단 단수에 대한 최댓값을 담을 배열


	for(int i=1; i<=input; i++){  
	value[i] = sc.nextInt();
       	 } // 계단 각각의 점수값을 배열에 담는 과정

	dp[1]=value[1];               // 1일 경우 1계단 값 
	dp[2]=value[1]+value[2]; //  2일 경우 1계단+2계단 값

	for(int i=3; i<=input; i++){
	dp[i]=max( dp[i-2]+value[i] , dp[i-3]+value[i-1]+value[i]); // 점화식
	}

	System.out. println(dp[n]); // 해당 계단의 최댓값 출력
	}
}