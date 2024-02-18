int a,b,c;


int bar(int a, int b,int d){	
	c = 4*a + 2*b + d;
	return c;
}


void func_a(){
	a = 7;
}




int foo(int a){
	a = a + 3;
	return a;
}




int bar2(int a, int b){	
	c = 4*a + 2*b;
	return c;
}

int main(){
 
	int i,j,k,l;
	
	i = 5;
	j = 6;
	
	func_a();
	println(a);
	
	k = foo(i);
	println(k);
	
	l = bar(i,j,k);
	println(l);
	
	j = 6 * bar(i,j,k) + 2 - 3 * foo(i);
	println(j);
	
 
	return 0;
}

