public class javathread{
	public static int num = 0;
	public static void main(String argv[]){
		myadd add = new myadd();
		Thread t1 = new Thread(add);
		Thread t2 = new Thread(add);
		Thread t3 = new Thread(add);
		Thread t4 = new Thread(add);
		t1.start();
		t2.start();
		t3.start();
		t4.start();
		try{
			t1.join();
			t2.join();
			t3.join();
			t4.join();

		}catch(InterruptedException ie){
			System.out.println(ie);
		}
		System.out.println("The count value is:" + num);

	}
}
class myadd implements Runnable {
	public void run(){
		for(int i = 0; i < 25000000; i++){
			javathread.num++;
			//System.out.println("I am thread" + Thread.currentThread().getName() + ", num is " + javathread.num); 
		}
		System.out.println("I am thread" + Thread.currentThread().getName() + ", num is " + javathread.num); 
	}
}
