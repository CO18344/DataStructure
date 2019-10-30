class stack
{
	public int[] data = new int[10];
	public int pos = -1;
	public void push(int key)
	{
		if(pos <= 9)
		{
			data[++pos] = key;
		}
		else
		{
			System.out.print("Stack is overflow");
		}
	}
	public int pop()
	{
		if(pos == -1)
		{
			System.out.print("Stack is underflow");
			return -1;
		}
		else
		{
			return data[pos--];
		}
	}
	public int peep()
	{
		if(pos < 0)
		{
			return data[pos];
		}
		else
		{
			System.out.print("Stack is underfow");
			return -1;
		}
	}

	public boolean isempty()
	{
		return pos == -1;
	}

	public boolean isfull()
	{
		return pos > 9;
	}

	public static void main(String[] args)
	{
		System.out.print("Create stack class and you can manuplate it");
	}
}
