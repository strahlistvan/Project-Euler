import java.util.*;

public class CountingSundays 
{
	public static void main(String[] args) 
	{
		Calendar currentDate = GregorianCalendar.getInstance();
		currentDate.set(1901, Calendar.JANUARY, 1); //kezdodatum
		Calendar destDate = GregorianCalendar.getInstance();
		destDate.set(2000, Calendar.DECEMBER, 31);  //celdatum
		    
		int counter = 0;
		//amig a jelenlegi datum kisebb, mint a cel
		while (currentDate.before(destDate))
		{
		    if (currentDate.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY && currentDate.get(Calendar.DAY_OF_MONTH) == 1)
		    {
		        ++counter;
		    	System.out.println(counter+". Sunday: "+currentDate.getTime());
		    }
	      currentDate.add(Calendar.DAY_OF_YEAR, 1); //novelem a napokat
	    }
	}   
}
