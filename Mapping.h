#pragma once
#pragma once
#include <set>
#include <string>
#include <vector>

using wcharset = std::set<std::wstring>;

// sets with all big chars and all small chars, for the get_wordsizes() function
wcharset is_small_char{ L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"p", L"q", L"r", L"s", L"t", L"u", L"v", L"w", L"x", L"y", L"z", L"ü", L"ö", L"ä", L"!", L"?", L".", L",", L"-", L":", L"*", L";" };
wcharset is_big_char{ L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"Ü", L"Ö", L"Ä" };

// sets of numbers and numbers + characters (that don't break the number prefix / number streak), for get_wordsizes() and print function
wcharset is_number = { L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9" };
wcharset is_numberspace_member = { L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L".", L"-", L"," };

// capital characters - mapping for print function
wcharset l1_left_capital = { L"A", L"B", L"E", L"H", L"K", L"L", L"O", L"R", L"U", L"V", L"Z", L"Ü" };
wcharset l1_right_capital = { L"I", L"J", L"S", L"T", L"W", L"Ä", L"Ö" };
wcharset l1_both_capital = { L"C", L"D", L"F", L"G", L"M", L"N", L"P", L"Q", L"X", L"Y" };
wcharset l1_none_capital = {};

wcharset l2_left_capital = { L"B", L"F", L"I", L"L", L"P", L"S", L"V", L"Ö" };
wcharset l2_right_capital = { L"D", L"E", L"N", L"O", L"Y", L"Z", L"Ä" };
wcharset l2_both_capital = { L"G", L"H", L"J", L"Q", L"R", L"T", L"W", L"Ü" };
wcharset l2_none_capital = { L"A", L"C", L"K", L"M" };

wcharset l3_left_capital = { L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"Ä" };
wcharset l3_right_capital = { L"Ö", L"w", L"Ü" };
wcharset l3_both_capital = { L"U", L"V", L"X", L"Y", L"Z" };
wcharset l3_none_capital = { L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J" };

// regular small characters - mapping for print function
wcharset l1_left = { L"a", L"b", L"e", L"h", L"k", L"l", L"o", L"r", L"u", L"v", L"z", L"ü" };
wcharset l1_right = { L"i", L"j", L"s", L"t", L"ß", L"w", L"ä", L"ö" };
wcharset l1_both = { L"c", L"d", L"f", L"g", L"m", L"n", L"p", L"q", L"x", L"y" };
wcharset l1_none = { L".", L",", L"?", L"!", L"-", L":", L";", L"*" };

wcharset l2_left = { L"b", L"f", L"i", L"l", L"p", L"s", L"v", L"ß", L"ö", L",", L"?", L";" };
wcharset l2_right = { L"d", L"e", L"n", L"o", L"y", L"z", L"ä", L"*" };
wcharset l2_both = { L"g", L"h", L"j", L"q", L"r", L"t", L"w", L"ü", L"!" };
wcharset l2_none = { L"a", L"c", L"k", L"m", L"u", L".", L"-", L":" };

wcharset l3_left = { L"k", L"l", L"m", L"n", L"o", L"p", L"q", L"r", L"s", L"t", L"ä", L".", L"!", L";", L"*" };
wcharset l3_right = { L"ö", L"w", L"ü", L"?" };
wcharset l3_both = { L"u", L"v", L"x", L"y", L"z", L"ß", L"-", L":" };
wcharset l3_none = { L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h", L"i", L"j", L"," };

// numberspace characters - mapping for print function
wcharset numberspace_l1_left = { L"1", L"2", L"5", L"8" };
wcharset numberspace_l1_right = { L"9", L"0" };
wcharset numberspace_l1_both = { L"3", L"4", L"6", L"7" };
wcharset numberspace_l1_none = { L".", L"-" };

wcharset numberspace_l2_left = { L"2", L"6", L"9" };
wcharset numberspace_l2_right = { L"9", L"0", L"4", L"5" };
wcharset numberspace_l2_both = { L"0", L"7", L"8" };
wcharset numberspace_l2_none = { L".", L"-", L"1", L"3", };

wcharset numberspace_l3_left = { L"." };
wcharset numberspace_l3_right = {};
wcharset numberspace_l3_both = { L"-" };
wcharset numberspace_l3_none = { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"0" };

// vector of sets for printfunction line 1
std::vector<wcharset> charset_l1 = { l1_left, l1_right, l1_both, l1_none,
                                 l1_left_capital, l1_right_capital, l1_both_capital, l1_none_capital,
                                 numberspace_l1_left, numberspace_l1_right, numberspace_l1_both, numberspace_l1_none };

// vector of sets for printfunction line 2
std::vector<wcharset> charset_l2 = { l2_left, l2_right, l2_both, l2_none,
                                 l2_left_capital, l2_right_capital, l2_both_capital, l2_none_capital,
                                 numberspace_l2_left, numberspace_l2_right, numberspace_l2_both, numberspace_l2_none };

// vector of sets for printfunction line 3
std::vector<wcharset> charset_l3 = { l3_left, l3_right, l3_both, l3_none,
                                 l3_left_capital, l3_right_capital, l3_both_capital, l3_none_capital,
                                 numberspace_l3_left, numberspace_l3_right, numberspace_l3_both, numberspace_l3_none };



