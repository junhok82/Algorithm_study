import java.util.Arrays;
import java.util.Scanner;
 
public class StairMax {

	public static void main(String[] args){
	int input = sc.netxInt(); 	  // ����Ǽ�
	int value[] = new int[input+1]; // ����� �������� ���� �迭
	int dp[] = new int[input+1];     // ������ ��� �ܼ��� ���� �ִ��� ���� �迭


	for(int i=1; i<=input; i++){  
	value[i] = sc.nextInt();
       	 } // ��� ������ �������� �迭�� ��� ����

	dp[1]=value[1];               // 1�� ��� 1��� �� 
	dp[2]=value[1]+value[2]; //  2�� ��� 1���+2��� ��

	for(int i=3; i<=input; i++){
	dp[i]=max( dp[i-2]+value[i] , dp[i-3]+value[i-1]+value[i]); // ��ȭ��
	}

	System.out. println(dp[n]); // �ش� ����� �ִ� ���
	}
}