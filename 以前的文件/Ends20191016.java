
package test;


public class Test {

    
    public static void main(String[] args) {
        int j;
        for(int i = 1;i <= 1000;i++){
            int sum = 0;//注意初始sum为零
            for(j = 1;j <= i/2;j++){
                if(i % j == 0)
                    sum = sum + j;
            }
            if(i == sum)
                System.out.println(i);
        }
    }
    
}

        System.out.println("输入正整数：");
        Scanner reader = new Scanner(System.in);
        int number = reader.nextInt();//获取键盘的输入：
                                          //如果执行到了这一行，那么程序会暂停，等待你在控制台输入，然后把输入的整数值赋给整型变量number
                                          //float number = reader.nextFloat();控制台输入赋值给浮点型变量number
        System.out.println("你输入的正整数为："+number);
        
        int xx[] = {2,32,435,5};
        int sum = 0;
        for(int y : xx)//类型跟数组类型一致，：右侧与数组名一致，y值可以替换成其他变量
            //只能用于数组求和
            sum = sum + y;
        System.out.println(sum);



package test;

import static java.lang.Math.PI;
import java.util.Scanner;


public class Test {
    Test(){
        double area = getArea(3.5f);
        System.out.println(area);
        A();
    }
    double getArea(float radius){
        return radius*radius*PI;
    }
    int xx[] = new int[3];
    int m = 0;
    int [] prefectNumber(){
        int j;
        for(int i = 1;i <= 1000;i++){
            int sum = 0;//注意初始sum为零
            for(j = 1;j <= i/2;j++){
                if(i % j == 0)
                    sum = sum + j;
            }
            if(i == sum){
                xx[m] = i;
                m++;
            }
        }
        return xx;
    }
    String name;
    int x = 100;//成员变量，有默认值0,对成员变量的赋值只能放在方法中
    void A(){
        int x = this.x;//第一个x为局部变量，无默认值
        System.out.println(x);
    }
    public static void main(String[] args) {
        Test tt = new Test();
        tt.name = "aaa";
        tt.getArea(5.1f);
    }
    
}
