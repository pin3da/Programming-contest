

### Key idea

```C++
long long f( int A[], int n ) { // n = size of A
  long long sum = 0;
  for( int i = 0; i < n; i++ ) {
    for( int j = i + 1; j < n; j++ )
      cout << A[i] << " - " << A[j] << endl;
    cout << endl;
  }
  return sum;
}
```
