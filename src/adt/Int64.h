#ifndef _INCLUDED_INT64
#define _INCLUDED_INT64

typedef int (Int64_comparef)(int64, int64);

typedef word (Int64_hashf)(int64);

int Int64_compare(int64, int64);

word Int64_hash(int64);

int Int64_getNumberOfBitOne(int64);

int Int64_inc(int64);

#endif // _INCLUDED_INT64
