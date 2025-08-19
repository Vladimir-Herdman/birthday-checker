#ifndef BIRTHDAYCHECKER_DATES_H
#define BIRTHDAYCHECKER_DATES_H

#include <string>

struct months {
    using Month = std::string;

    static constexpr Month january[31] = {
        "testjan"
    };
    static constexpr Month february[29] = {
    };
    static constexpr Month march[31] = {
    };
    static constexpr Month april[30] = {
    };
    static constexpr Month may[31] = {
    };
    static constexpr Month june[30] = {
    };
    static constexpr Month july[31] = {
    };
    static constexpr Month august[31] = {
    };
    static constexpr Month september[30] = {
    };
    static constexpr Month october[31] = {
    };
    static constexpr Month november[30] = {
        [23] = "self",
    };
    static constexpr Month december[31] = {
    };

    static constexpr const Month* m_month_table[12] = {january, february, march, april, may, june, july, august, september, october, november, december};
    // We use 1 indexing to easify month numbering
    static constexpr const std::basic_string<char> *const at(const size_t idx) {return m_month_table[idx-1];}
};

enum class dates {
    JAN_1 = 0, JAN_2, JAN_3, JAN_4, JAN_5, JAN_6, JAN_7,
    JAN_8, JAN_9, JAN_10, JAN_11, JAN_12, JAN_13, JAN_14,
    JAN_15, JAN_16, JAN_17, JAN_18, JAN_19, JAN_20, JAN_21,
    JAN_22, JAN_23, JAN_24, JAN_25, JAN_26, JAN_27, JAN_28,
    JAN_29, JAN_30, JAN_31, 

    FEB_1 = 0, FEB_2, FEB_3, FEB_4, FEB_5, FEB_6, FEB_7,
    FEB_8, FEB_9, FEB_10, FEB_11, FEB_12, FEB_13, FEB_14,
    FEB_15, FEB_16, FEB_17, FEB_18, FEB_19, FEB_20, FEB_21,
    FEB_22, FEB_23, FEB_24, FEB_25, FEB_26, FEB_27, FEB_28,
    FEB_29,

    MARCH_1 = 0, MARCH_2, MARCH_3, MARCH_4, MARCH_5, MARCH_6, MARCH_7,
    MARCH_8, MARCH_9, MARCH_10, MARCH_11, MARCH_12, MARCH_13, MARCH_14,
    MARCH_15, MARCH_16, MARCH_17, MARCH_18, MARCH_19, MARCH_20, MARCH_21,
    MARCH_22, MARCH_23, MARCH_24, MARCH_25, MARCH_26, MARCH_27, MARCH_28,
    MARCH_29, MARCH_30, MARCH_31, 

    APRIL_1 = 0, APRIL_2, APRIL_3, APRIL_4, APRIL_5, APRIL_6, APRIL_7,
    APRIL_8, APRIL_9, APRIL_10, APRIL_11, APRIL_12, APRIL_13, APRIL_14,
    APRIL_15, APRIL_16, APRIL_17, APRIL_18, APRIL_19, APRIL_20, APRIL_21,
    APRIL_22, APRIL_23, APRIL_24, APRIL_25, APRIL_26, APRIL_27, APRIL_28,
    APRIL_29, APRIL_30,

    MAY_1 = 0, MAY_2, MAY_3, MAY_4, MAY_5, MAY_6, MAY_7,
    MAY_8, MAY_9, MAY_10, MAY_11, MAY_12, MAY_13, MAY_14,
    MAY_15, MAY_16, MAY_17, MAY_18, MAY_19, MAY_20, MAY_21,
    MAY_22, MAY_23, MAY_24, MAY_25, MAY_26, MAY_27, MAY_28,
    MAY_29, MAY_30, MAY_31, 

    JUNE_1 = 0, JUNE_2, JUNE_3, JUNE_4, JUNE_5, JUNE_6, JUNE_7,
    JUNE_8, JUNE_9, JUNE_10, JUNE_11, JUNE_12, JUNE_13, JUNE_14,
    JUNE_15, JUNE_16, JUNE_17, JUNE_18, JUNE_19, JUNE_20, JUNE_21,
    JUNE_22, JUNE_23, JUNE_24, JUNE_25, JUNE_26, JUNE_27, JUNE_28,
    JUNE_29, JUNE_30,

    JULY_1 = 0, JULY_2, JULY_3, JULY_4, JULY_5, JULY_6, JULY_7,
    JULY_8, JULY_9, JULY_10, JULY_11, JULY_12, JULY_13, JULY_14,
    JULY_15, JULY_16, JULY_17, JULY_18, JULY_19, JULY_20, JULY_21,
    JULY_22, JULY_23, JULY_24, JULY_25, JULY_26, JULY_27, JULY_28,
    JULY_29, JULY_30, JULY_31, 

    AUG_1 = 0, AUG_2, AUG_3, AUG_4, AUG_5, AUG_6, AUG_7,
    AUG_8, AUG_9, AUG_10, AUG_11, AUG_12, AUG_13, AUG_14,
    AUG_15, AUG_16, AUG_17, AUG_18, AUG_19, AUG_20, AUG_21,
    AUG_22, AUG_23, AUG_24, AUG_25, AUG_26, AUG_27, AUG_28,
    AUG_29, AUG_30, AUG_31, 

    SEPT_1 = 0, SEPT_2, SEPT_3, SEPT_4, SEPT_5, SEPT_6, SEPT_7,
    SEPT_8, SEPT_9, SEPT_10, SEPT_11, SEPT_12, SEPT_13, SEPT_14,
    SEPT_15, SEPT_16, SEPT_17, SEPT_18, SEPT_19, SEPT_20, SEPT_21,
    SEPT_22, SEPT_23, SEPT_24, SEPT_25, SEPT_26, SEPT_27, SEPT_28,
    SEPT_29, SEPT_30,

    OCT_1 = 0, OCT_2, OCT_3, OCT_4, OCT_5, OCT_6, OCT_7,
    OCT_8, OCT_9, OCT_10, OCT_11, OCT_12, OCT_13, OCT_14,
    OCT_15, OCT_16, OCT_17, OCT_18, OCT_19, OCT_20, OCT_21,
    OCT_22, OCT_23, OCT_24, OCT_25, OCT_26, OCT_27, OCT_28,
    OCT_29, OCT_30, OCT_31, 

    NOV_1 = 0, NOV_2, NOV_3, NOV_4, NOV_5, NOV_6, NOV_7,
    NOV_8, NOV_9, NOV_10, NOV_11, NOV_12, NOV_13, NOV_14,
    NOV_15, NOV_16, NOV_17, NOV_18, NOV_19, NOV_20, NOV_21,
    NOV_22, NOV_23, NOV_24, NOV_25, NOV_26, NOV_27, NOV_28,
    NOV_29, NOV_30,

    DEC_1 = 0, DEC_2, DEC_3, DEC_4, DEC_5, DEC_6, DEC_7,
    DEC_8, DEC_9, DEC_10, DEC_11, DEC_12, DEC_13, DEC_14,
    DEC_15, DEC_16, DEC_17, DEC_18, DEC_19, DEC_20, DEC_21,
    DEC_22, DEC_23, DEC_24, DEC_25, DEC_26, DEC_27, DEC_28,
    DEC_29, DEC_30, DEC_31
};

#endif //BIRTHDAYCHECKER_DATES_H
