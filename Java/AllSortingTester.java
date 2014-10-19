import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;

public class AllSortingTester
{
	public static void main(String[] args)
	{
		int[] original = createRandomArray(Integer.parseInt(args[0]));
		int[] test;
		
		long startTime;
		long stopTime;
		long elapsedTime;
		
		System.out.println("\nPanjang array : " + original.length + "\n");
		/*
		//testing bubble sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		bubbleSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Bubble sort    : " + elapsedTime + " milliseconds");
		
		//testing selection sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		selectionSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Selection sort : " + elapsedTime + " milliseconds");
		
		//testing insertion sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		insertionSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Insertion sort : " + elapsedTime + " milliseconds");
		*/
		
		//testing shell sort gap dibagi 2
		test = original.clone();
		startTime = System.currentTimeMillis();
		shellSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		
		System.out.println("Shell sort 2   : " + elapsedTime + " milliseconds");
		
		//testing shell sort gap dibagi 2.2
		test = original.clone();
		startTime = System.currentTimeMillis();
		shellSort2(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Shell sort 2.2 : " + elapsedTime + " milliseconds");
		
		//testing shell sort gap ganjil
		test = original.clone();
		startTime = System.currentTimeMillis();
		shellSort3(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Shell sort odd : " + elapsedTime + " milliseconds");
		
		//testing merge sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		mergeSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Merge sort     : " + elapsedTime + " milliseconds");
		
		//testing quick sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		quickSort(test, 0, test.length-1);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Quick sort     : " + elapsedTime + " milliseconds");
		
		//testing counting sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		test = countingSort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Counting sort  : " + elapsedTime + " milliseconds");
		
		//testing Arrays.sort
		test = original.clone();
		startTime = System.currentTimeMillis();
		Arrays.sort(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("Arrays.sort    : " + elapsedTime + " milliseconds");

		//testing PriorityQueue
		test = original.clone();
		startTime = System.currentTimeMillis();
		//printArray(test);
		PriorityQueueSort(test);
		//printArray(test);
		stopTime = System.currentTimeMillis();
		elapsedTime = stopTime - startTime;
		System.out.println("PQ Sort        : " + elapsedTime + " milliseconds");
	}
	
	public static void shuffle(int[] array) {
        Random random = new Random();
        int count = array.length;
        for (int i = count; i > 1; i--) {
			int j = random.nextInt(i);
			int temp = array[i-1];
			array[i-1] = array[j];
			array[j] = temp;
        }
    }
	
	public static void printArray(int[] arr)
	{
		System.out.println(Arrays.toString(arr));
	}
	
	public static int[] createRandomArray(int size)
	{
		int[] arr = new int[size];
		for (int i=0; i<size; i++){
			arr[i] = i;
		}
		shuffle(arr);
		return arr;
	}
	
	public static int[] createSortedArray(int size)
	{
		int[] arr = new int[size];
		for (int i=0; i<size; i++){
			arr[i] = i;
		}
		return arr;
	}
	
	//bubble Sort
	public static void bubbleSort(int[] a)
	{
		for (int i = a.length-1; i>=0; i--) {
			boolean swapped = false;
			for (int j = 0; j<i; j++) {
				if (a[j] > a[j+1]) {
					int T = a[j];
					a[j] = a[j+1];
					a[j+1] = T;
					swapped = true;
				}
			}
			if (!swapped)
				return;
		}
	}
	
	//selection sort
	public static void selectionSort(int[] a)
	{
		for (int i = 0; i < a.length; i++) {
		  int min = i;

		   for (int j = i + 1; j < a.length; j++)
				if (a[j] < a[min])
					min = j;
				

		   int T = a[min];
		   a[min] = a[i];
		   a[i] = T;
		}
	}

	//PriorityQueue sort
	public static void PriorityQueueSort(int[] a) {
		PriorityQueue<Integer> p = new PriorityQueue<Integer>();
		int len = a.length;
		for(int i = 0; i < len; i++) {
			p.add(a[i]);
		}
		int i = 0;
		while(true) {
			Integer x = p.poll();
			if(x == null) {
				break;
			}
			a[i++] = x;
		}
	}
	
	//insertion sort
	public static void insertionSort(int[] a)
	{
		for (int i = 1; i < a.length; i++) 
		{
			int temp = a[i];
			int j = i;
			while (( j > 0) && (temp < a[j - 1]))     
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = temp;
		}
	}
	
	//shell sort gap dibagi 2
	public static void shellSort(int[] a)
	{
		int i1, i, j, gap, temp, n = a.length;
        /* Shell Sort Program */
        for (gap = n / 2; gap > 0; gap = gap / 2)
        {
            for (i = gap; i < n; i++)
            {
                temp = a[i];
                for (j = i; j >= gap; j -= gap) 
                {
                    if (temp < a[j - gap]) 
					    a[j] = a[j - gap];
					else 
						break;
                }
                a[j] = temp;
            }
        }
	}
	
	//shell sort gap dibagi 2.2
	public static void shellSort2(int[] a)
	{
		int i1, i, j, gap, temp, n = a.length;
        /* Shell Sort Program */
        for (gap = n / 2; gap > 0; gap = gap == 2 ? 1 : (int) (gap / 2.2))
        {
            for (i = gap; i < n; i++)
            {
                temp = a[i];
                for (j = i; j >= gap; j -= gap) 
                {
                    if (temp < a[j - gap]) 
					    a[j] = a[j - gap];
					else 
						break;
                }
                a[j] = temp;
            }
        }
	}
	
	//shell sort gap ganjil
	public static void shellSort3(int[] a)
	{
		int i1, i, j, gap, temp, n = a.length;
        /* Shell Sort Program */
        for (gap = n/2 - 1; gap > 0; gap = gap/2-1)
        {
            for (i = gap; i < n; i++)
            {
                temp = a[i];
                for (j = i; j >= gap; j -= gap) 
                {
                    if (temp < a[j - gap]) 
					    a[j] = a[j - gap];
					else 
						break;
                }
                a[j] = temp;
            }
        }
	}
	
	//merge sort
	public static void mergeSort(int[] A) {
        if (A.length > 1) {
            int q = A.length/2;

            int[] leftArray = Arrays.copyOfRange(A, 0, q);
            int[] rightArray = Arrays.copyOfRange(A,q,A.length);

            mergeSort(leftArray);
            mergeSort(rightArray);

            merge(A,leftArray,rightArray);
        }
    }
	
	public static void merge(int[] a, int[] b, int[] c) {
        int i = 0; //counter array b
		int j = 0; //counter array c
		int k = 0; //counter array a, array hasil/output
		
		while(i < b.length && j < c.length)
		{
			if (b[i] < c[j])
			{
				a[k] = b[i];
				i++;
				k++;
			}
			else
			{
				a[k] = c[j];
				j++;
				k++;
			}
		}
		
		while(i < b.length)
		{
			a[k] = b[i];
			i++;
			k++;
		}
		
		while(j < c.length)
		{
			a[k] = c[j];
			j++;
			k++;
		}
    }
	
	//quick sort
	public static void quickSort(int a[], int low, int high) 
	{
		if(high <= low) return; // base case
		int pivotIdx = low; // select "best" pivot
		int pivot = a[pivotIdx];

		swap (a, pivotIdx, high);     // move pivot out of the way
		int i = low, j = high-1;
		while (i <= j) {
			// find large element starting from left
			while (i<high && a[i]<pivot) i++;
			// find small element starting from right
			while (j>=low && a[j]>=pivot) j--;
			
			// if the indexes have not crossed, swap
			if (i < j) swap (a, i, j);
		}
		swap(a,i,high);       // restore pivot to index i
		quickSort (a, low, i-1);   // sort small elements
		quickSort (a, i+1, high);  // sort large elements
		return;
	}
	
	private static void swap(int[] a, int i, int j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	//counting sort
	public static int[] countingSort(int[] a) //T(n) = 3n = O(n)
	{
		int maxValue = getMaxVal(a);       //O(n)
		int[] sortedArray = new int[a.length]; //c
		int[] tempArray = new int[maxValue + 1]; //c
		
		for (int i = 0; i < a.length; i++)   //n
		{
			tempArray[a[i]] = tempArray[a[i]] + 1;
		}
		
		for (int i = 1; i < maxValue + 1; i++) //n
		{
			tempArray[i] = tempArray[i] + tempArray[i - 1];
		}
		  
		for (int i = (a.length - 1); i >= 0; i--) //n
		{
			sortedArray[tempArray[a[i]] - 1] = a[i];
			tempArray[a[i]] = tempArray[a[i]] - 1;
		}
		return sortedArray;
	}
	
	private static int getMaxVal(int[] arrayToSort)
	{
		int maxVal = Integer.MIN_VALUE;
		for (int i : arrayToSort)
		{
			if (i > maxVal)
				maxVal = i;
		}
		return maxVal;
	}
	
	private static boolean isSorted(int[] a)
	{
		for(int i = 0; i < a.length-1; i++)
		{
			if (a[i] > a[i+1])
				return false;
		}
		return true;
	}
}