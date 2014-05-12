﻿/**----------------------------------------------------------------------------
 * _MyLib_test.cpp
 *-----------------------------------------------------------------------------
 * 
 *-----------------------------------------------------------------------------
 * All rights reserved by Noh,Yonghwan (fixbrain@gmail.com, unsorted@msn.com)
 *-----------------------------------------------------------------------------
 * 2014:1:25 13:34 created
**---------------------------------------------------------------------------*/
#include "stdafx.h"

bool test_x64_calling_convension();
bool test_std_string_find_and_substr();
bool test_to_lower_uppper_string();
//bool test_const_position();
bool test_initialize_string();

// _test_cpp_test.cpp
bool test_cpp_class();

// win32utils.cpp
bool test_get_filepath_by_handle();
bool test_nt_name_to_dos_name();
bool test_query_dos_device();
bool test_bin_to_hex();
bool test_str_to_xxx();

// _test_boost.cpp
extern bool boost_lexical_cast();
extern bool boost_shared_ptr_void();
extern bool boost_shared_ptr_handle_01();
extern bool boost_shared_ptr_handle_02();
extern bool boost_shared_ptr_handle_03();
extern bool boost_tuple();

// _test_boost_bind.cpp
extern bool boost_bind();
extern bool boost_bind2();
extern bool boost_bind3();
extern bool boost_bind4();

// _test_std_map.cpp
extern bool test_std_map();
extern bool test_map_plus_algorithm_1();
extern bool test_map_plus_algorithm_2();
extern bool test_map_plus_algorithm_3();
extern bool test_map_plus_algorithm_4();

class ccc
{
public:
	~ccc ()
	{
		log_info L"..." log_end
	}
};
/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
int _tmain(int argc, _TCHAR* argv[])
{
	bool ret = false;
	UINT32 _pass_count = 0;
	UINT32 _fail_count = 0;

	//assert_bool(true, test_x64_calling_convension);
	//assert_bool(true, test_std_string_find_and_substr);
	//assert_bool(true, test_to_lower_uppper_string);
	////assert_bool(true, test_const_position);
	//assert_bool(true, test_initialize_string);
	
	//assert_bool(true, test_cpp_class);

	//assert_bool(true, test_nt_name_to_dos_name);
	//assert_bool(true, test_query_dos_device);
	//assert_bool(true, test_get_filepath_by_handle);
	//assert_bool(true, test_bin_to_hex);
	assert_bool(true, test_str_to_xxx);

	//assert_bool(true, boost_lexical_cast);
	/*
	assert_bool(true, boost_shared_ptr_void);
	assert_bool(true, boost_shared_ptr_handle_01);
	assert_bool(true, boost_shared_ptr_handle_02);
	assert_bool(true, boost_shared_ptr_handle_03);

	assert_bool(true, boost_tuple);

	assert_bool(true, boost_bind);
	assert_bool(true, boost_bind2);
	assert_bool(true, boost_bind3);
	assert_bool(true, boost_bind4);

	assert_bool(true, test_std_map);
	assert_bool(true, test_map_plus_algorithm_1);
	assert_bool(true, test_map_plus_algorithm_2);
	assert_bool(true, test_map_plus_algorithm_3);
	assert_bool(true, test_map_plus_algorithm_4);
	*/

	log_info
		L"-------------------------------------------------------------------------------"
	log_end
	log_info
		L"total test = %u, pass = %u, fail = %u", 
		_pass_count + _fail_count, 
		_pass_count, 
		_fail_count
	log_end

	return 0;
}

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_std_string_find_and_substr()
{
	std::wstring nt_name(L"\\Device\\HarddiskVolume1\\Windows\\system32\\drivers");
	std::wstring dos_device_name(L"c:");
	std::wstring nt_device_name(L"\\Device\\HarddiskVolume1");
	std::wstring nt_device_name2(L"\\DEVICE\\HarddiskVolume1");		// 대문자


	//> 대소문자가 일치하는 경우 string::find 가 정상 동작 함
	size_t pos = nt_name.find(nt_device_name);
	if (std::wstring::npos == pos) return false;

	std::wstring out = dos_device_name + 
						nt_name.substr(pos + nt_device_name.size(), nt_name.size());
	
	log_dbg
		L"\nnt_name = %s \ndos_device_name = %s \nnt_device_name = %s \nresult = %s",
		nt_name.c_str(),
		dos_device_name.c_str(),
		nt_device_name.c_str(),
		out.c_str()
	log_end

	//> 대소문자 구분 없이 find 하려면 win32util::to_lower_string() 호출 후 비교해야 함
	pos = nt_name.find(nt_device_name2);
	if (std::wstring::npos == pos) return true;

	return true;
}

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/

/*
	int func_many_param(int a, int b, int c, int d, int e, int f)
	{
	000000013FA77530  mov         dword ptr [rsp+20h],r9d  
	000000013FA77535  mov         dword ptr [rsp+18h],r8d  
	000000013FA7753A  mov         dword ptr [rsp+10h],edx  
	000000013FA7753E  mov         dword ptr [rsp+8],ecx  
	000000013FA77542  push        rdi  
		return 0;
	000000013FA77543  xor         eax,eax  
	}
	000000013FA77545  pop         rdi  
	000000013FA77546  ret 
*/
int func_many_param(int a, int b, int c, int d, int e, int f)
{
	return 0;
}

/*
	int func_four_param(int a, int b, int c, int d)
	{
	000000013FA77550  mov         dword ptr [rsp+20h],r9d  
	000000013FA77555  mov         dword ptr [rsp+18h],r8d  
	000000013FA7755A  mov         dword ptr [rsp+10h],edx  
	000000013FA7755E  mov         dword ptr [rsp+8],ecx  
	000000013FA77562  push        rdi  
		return 0;
	000000013FA77563  xor         eax,eax  
	}
	000000013FA77565  pop         rdi  
	000000013FA77566  ret  
*/
int func_four_param(int a, int b, int c, int d)
{
	return 0;
}

/*
	int func_few_param(int a, int b)
	{
	000000013FA77570  mov         dword ptr [rsp+10h],edx  
	000000013FA77574  mov         dword ptr [rsp+8],ecx  
	000000013FA77578  push        rdi  
		return 0;
	000000013FA77579  xor         eax,eax  
	}
	000000013FA7757B  pop         rdi  
	000000013FA7757C  ret  
*/
int func_few_param(int a, int b)
{
	return 0;
}

/*
	bool test_x64_calling_convension()
	{
	000000013FA77590  push        rdi  
	000000013FA77592  sub         rsp,40h  
	000000013FA77596  mov         rdi,rsp  
	000000013FA77599  mov         ecx,10h  
	000000013FA7759E  mov         eax,0CCCCCCCCh  
	000000013FA775A3  rep stos    dword ptr [rdi]  
		int ret = func_few_param(1,2);
	000000013FA775A5  mov         edx,2  
	000000013FA775AA  mov         ecx,1  
	000000013FA775AF  call        000000013FA532F1  
	000000013FA775B4  mov         dword ptr [rsp+30h],eax  
		ret = func_four_param(1,2,3,4);
	000000013FA775B8  mov         r9d,4  
	000000013FA775BE  mov         r8d,3  
	000000013FA775C4  mov         edx,2  
	000000013FA775C9  mov         ecx,1  
	000000013FA775CE  call        000000013FA51A05  
	000000013FA775D3  mov         dword ptr [rsp+30h],eax  
		ret = func_many_param(1,2,3,4,5,6);
	000000013FA775D7  mov         dword ptr [rsp+28h],6  
	000000013FA775DF  mov         dword ptr [rsp+20h],5  
	000000013FA775E7  mov         r9d,4  
	000000013FA775ED  mov         r8d,3  
	000000013FA775F3  mov         edx,2  
	000000013FA775F8  mov         ecx,1  
	000000013FA775FD  call        000000013FA52AEA  
	000000013FA77602  mov         dword ptr [rsp+30h],eax  
		return true;
	000000013FA77606  mov         al,1  
	}
	000000013FA77608  add         rsp,40h  
	000000013FA7760C  pop         rdi  
	000000013FA7760D  ret  
*/
bool test_x64_calling_convension()
{
	int ret = func_few_param(1,2);
	ret = func_four_param(1,2,3,4);
	ret = func_many_param(1,2,3,4,5,6);
	return true;
}

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_to_lower_uppper_string()
{
	std::wstring str = L"ABCDEFGh1234";
	log_msg L"str = %s", str.c_str() log_end
	to_lower_string(str);
	log_msg L"after to_lower, str = %s", str.c_str() log_end

	to_upper_string(str);
	log_msg L"after to_upper, str = %s", str.c_str() log_end

	return true;
}

/**
 * @brief	const 위치 / 의미 
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
/*
class ConstPositionTest
{
public:	
	//> (const char*) msg : char* 가 const, 즉 msg 가 가리키는 데이터 변경 불가
    char* Function1(const char* msg)  
    {
        msg[0] = 't'; // error
        return m_msg;
    }

	//> char* (const msg) : msg 변수가 const, 즉 msg 포인터 변수 변경 불가
    char* Function2(char* const msg)  
    {    
        msg = m_msg; //error
        return m_msg;
    }

	//> 메소드 상수화, 이 메소드는 클래스 멤버를 읽을 수는 있으나 변경 할 수는 없음
    char* Function3(char* msg) const 
    {
        m_msg = msg; //error
        return m_msg;  
    }

	//> (const char*) : 리턴 값이 const char* 이므로 리턴 받는 변수도 const char* 이어야 함
	//> 따라서 리턴되는 포인터가 가리키는 데이터 변경 불가
    const char* Function4(char* msg)  
    {
        m_msg = msg;
        return m_msg; //반환 받는 타입이 const가 아닐 경우 error
    }
private:
    char* m_msg;
};

bool test_const_position()
{
	ConstPositionTest test;
	char msg[] = "hello, const!";
 
	 test.Function1(msg);
	 test.Function2(msg);
	 test.Function3(msg);

	 const char* pMessage = test.Function4(msg);
	 pMessage[0] = 0; // error
}
*/

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_initialize_string()
{
	std::wstring str = L"";
	log_dbg L"str = %s", str.c_str() log_end

	//> invalid null point exception 발생 
	//> try-except 로 못 잡음... 
	//> 초기화시 NULL 이면 L"" 로 바꿔서 초기화 해야 함
/*
	try
	{
		std::wstring str2 = NULL;
		log_dbg L"str2 = %s", str2.c_str() log_end
	}
	catch (...)
	{
		log_err L"oops" log_end
	}
*/	
	
	return true;
}



/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_get_filepath_by_handle()
{
	typedef boost::shared_ptr< boost::remove_pointer<HANDLE>::type > shared_file_handle;
	shared_file_handle file_handle(
							open_file_to_read(L"c:\\windows\\system32\\drivers\\etc\\hosts"), 
							CloseHandle
							);
	std::wstring file_path;
	bool ret = get_filepath_by_handle(file_handle.get(), file_path);
	if (true == ret)
	{
		log_dbg L"file path = %s", file_path.c_str() log_end
	}

	return ret;
}


/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_nt_name_to_dos_name()
{
	WCHAR*	nt_name = L"\\Device\\HarddiskVolume2\\Windows\\System32\\drivers\\etc\\hosts";
	std::wstring dos_name;

	bool ret = nt_name_to_dos_name(nt_name, dos_name);
	if (true == ret) 
	{
		log_dbg 
			L"nt_name = %s -> dos_name = %s", 
			nt_name,
			dos_name.c_str()
		log_end
	}
	return ret;
}

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_query_dos_device()
{
	wchar_t* dos_device = L"c:";
	std::wstring nt_device;

	bool ret = query_dos_device(dos_device, nt_device);
	if (true == ret) 
	{
		log_dbg 
			L"dos_device( %s ) -> nt_device ( %s )", 
			dos_device, 
			nt_device.c_str()
		log_end
	}

	return ret;
}

/**
	* @brief	
	* @param	
	* @see		
	* @remarks	
	* @code		
	* @endcode	
	* @return	
**/
bool test_bin_to_hex()
{
	/*
	01003689 > $ E8 C5F9FFFF    CALL notepad.01003053
	0100368E   . 6A 58          PUSH 58
	01003690   . 68 A0370001    PUSH notepad.010037A0
	01003695   . E8 72040000    CALL notepad.01003B0C
	0100369A   . 33DB           XOR EBX,EBX
	0100369C   . 895D E4        MOV DWORD PTR SS:[EBP-1C],EBX
	0100369F   . 895D FC        MOV DWORD PTR SS:[EBP-4],EBX
	010036A2   . 8D45 98        LEA EAX,DWORD PTR SS:[EBP-68]
	010036A5   . 50             PUSH EAX                                 ; /pStartupinfo
	010036A6   . FF15 FC100001  CALL DWORD PTR DS:[<&KERNEL32.GetStartup>; \GetStartupInfoA
	=>
	E8C5F9FFFF6A5868A0370001E87204000033DB895DE4895DFC8D459850FF15FC100001
	*/
	const char* orgau = "E8C5F9FFFF6A5868A0370001E87204000033DB895DE4895DFC8D459850FF15FC100001";
	const char* orgal = "e8c5f9ffff6a5868a0370001e87204000033db895de4895dfc8d459850ff15fc100001";
	const wchar_t* orgwu = L"E8C5F9FFFF6A5868A0370001E87204000033DB895DE4895DFC8D459850FF15FC100001";
	const wchar_t* orgwl = L"e8c5f9ffff6a5868a0370001e87204000033db895de4895dfc8d459850ff15fc100001";
	
	UINT8 code[] = {
					0xE8, 0xC5, 0xF9, 0xFF, 
					0xFF, 0x6A, 0x58, 0x68, 
					0xA0, 0x37, 0x00, 0x01, 
					0xE8, 0x72, 0x04, 0x00, 
					0x00, 0x33, 0xDB, 0x89, 
					0x5D, 0xE4, 0x89, 0x5D, 
					0xFC, 0x8D, 0x45, 0x98, 
					0x50, 0xFF, 0x15, 0xFC, 
					0x10, 0x00, 0x01		
					};

	std::string hexa;
	if (true != bin_to_hexa(sizeof(code), code, true, hexa)) return false;	
	if (0 != hexa.compare(orgau)) return false;
	
	if (true != bin_to_hexa(sizeof(code), code, false, hexa)) return false;	
	if (0 != hexa.compare(orgal)) return false;
	
	std::wstring hexw;
	if (true != bin_to_hexw(sizeof(code), code, true, hexw)) return false;	
	if (0 != hexw.compare(orgwu)) return false;

	if (true != bin_to_hexw(sizeof(code), code, false, hexw)) return false;	
	if (0 != hexw.compare(orgwl)) return false;
	
	return true;
}

/**
 * @brief	
 * @param	
 * @see		
 * @remarks	
 * @code		
 * @endcode	
 * @return	
**/
bool test_str_to_xxx()
{
	INT32	int32 = 0;
	UINT32	uint32 = 0;
	INT64	int64 = 0;
	UINT64	uint64 = 0;


	//>
	//> str_to_int32()
	//>
	if (true != str_to_int32("-1", int32)) return false;
	if (-1 != int32) return false;

	// NULL
	if (false != str_to_int32(NULL, int32)) return false;

	// invalid str = return true & 0
	if (true != str_to_int32("invalid str", int32)) return false;
	if (0 != int32) return false;

	// -0 
	if (true != str_to_int32("-0", int32)) return false;
	if (0 != int32) return false;

	// INT_MAX + 1 
	if (false != str_to_int32("2147483648", int32)) return false;

	// INT_MIN -1 => (-2147483647 - 1) -1 = -2147483649
	if (false != str_to_int32("-2147483649", int32)) return false;



	//>
	//> str_to_uint32()
	//>

	if (true != str_to_uint32("101010", uint32)) return false;
	if (101010 != uint32) return false;
	
	// -1
	if (false != str_to_uint32("-1", uint32)) return false;
	
	// NULL
	if (false != str_to_uint32(NULL, uint32)) return false;

	// invalid str = return true & 0
	if (true != str_to_uint32("invalid str", uint32)) return false;
	if (0 != uint32) return false;
			
	// UINT_MAX + 1	
	if (false != str_to_uint32("4294967296", uint32)) return false;



	
	//>
	//> str_to_int64()
	//>

	if (true != str_to_int64("-1", int64)) return false;
	if (-1 != int64) return false;

	// NULL
	if (false != str_to_int64(NULL, int64)) return false;

	// invalid str = return true & 0
	if (true != str_to_int64("invalid str", int64)) return false;
	if (0 != int64) return false;

	// -0 
	if (true != str_to_int64("-0", int64)) return false;
	if (0 != int64) return false;

	//INT64_MAX (9223372036854775807) + 1 = ffffffff`ffffffff
	if (false != str_to_int64("9223372036854775808", int64)) return false;

	//INT64_MIN (-9223372036854775807 -1) -1 = 9223372036854775809
	if (false != str_to_int64("-9223372036854775809", int64)) return false;

	

	//>
	//> str_to_uint64()
	//>

	if (false != str_to_uint64("-1", uint64)) return false;
	
	// NULL
	if (false != str_to_uint64(NULL, uint64)) return false;

	// invalid str = return true & 0
	if (true != str_to_uint64("invalid str", uint64)) return false;
	if (0 != uint64) return false;
		
	// UINT64_MAX (0xffffffff`ffffffff) + X
	if (false != str_to_uint64("9999999223372036854775807", uint64)) return false;
	

	return true;
}