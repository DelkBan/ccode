//���ַ� 
Position BinarySearch( List L, ElementType X )
{
	int ret = NotFound; //Ĭ��1���Ҳ�������-1 
	int start = 1;//��ʼλ��
	//int end = L.Last;//����λ�� 
	int m;//�м�λ��
	while(start <= L->Last) //�����յ�С��ʱ��ѭ��
	{
		m=start + (L->Last - start )/2 ;//ȡ��ǰ�е�
		if(L->Data[m] == X) //�����ȣ��õ���������� 
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

