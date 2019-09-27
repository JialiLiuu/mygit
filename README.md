# mygit

package test20190926;

public class Test20190926 {

    public static void main(String[] args) {
        for(int i = 3;i <= 1000;i++){//若这个整数等于除本身之外的因数之和，则输出
            int sum = 0;
            for(int j = 1;j <= i/2;j++){
                if(i%j == 0){
                    sum = sum+j;
                }
            }
            if(sum == i){
                System.out.println(i);
            }
        }
        int j;
        for(int i = 3;i <= 100;i++){//输出质数
            for(j = 2;j < i;j++){
                if(i%j == 0){
                    break;
                }
            }
            if(j >= i/2){
                System.out.println(i);
            }
        }
        int x[] = {12,34,23,123,5677,347};
        char s[] = {'s','w','u','f','e'};
        for(int a : x){
            System.out.println(a);
        }
        for(char a : s){
            System.out.print(a);
        }
    }
    
}
