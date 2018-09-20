//二分法 
Position BinarySearch( List L, ElementType X )
{
	int ret = NotFound; //默认1，找不到返回-1 
	int start = 1;//初始位置
	//int end = L.Last;//结束位置 
	int m;//中间位置
	while(start <= L->Last) //起点比终点小的时候循环
	{
		m=start + (L->Last - start )/2 ;//取当前中点
		if(L->Data[m] == X) //如果相等，得到结果，跳出 
		{
			ret = m;
			break;
		 } 
		 else if(L->Data[m]>X) 
		 {
		 	L->Last = m - 1;
		  } 
		  else
		  	{start = m + 1;}
	 } 
	return ret;
	
}

