import java.util.ArrayList;
import java.util.Iterator;
import java.util.*;
import java.util.List;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Dosya dosya=new Dosya("Kisiler.txt","sayilar.txt");
		List<String> list = new ArrayList<String>() ;
		for(int i=0;i<dosya.sayiDondur().size();i++) {
			System.out.println(dosya.sayiDondur().get(i));
		}
		for(int i=0;i<dosya.kisiDondur().size();i++) {
			System.out.println(dosya.kisiDondur().get(i).getName());
		}

	}

}
