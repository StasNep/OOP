#include "credit.h"
#include <cmath>
#include <string>

// Конструктор
Credit::Credit() {
    debt = 0.0;
    rate = 0.0;
    month_left = 0;
}

Credit::Credit(double Debt, double Rate, unsigned Left) {
    debt = x;
    rate = y;
    month_left = z;
}

// Геттер суммы кредита
double Credit::get_debt() {
    return debt;
}

// Геттер кредитной ставки
double Credit::get_rate() {
    return rate;
}

// Геттер срока кредита
unsigned Credit::get_month_left() {
    return month_left;
}

// Сеттер суммы кредита
void Credit::set_debt(double x) {
    debt = x;
}

// Сеттер кредитной ставки
void Credit::set_rate(double x) {
    rate = x;
}

// Сеттер срока кредита
void Credit::set_month_left(unsigned x) {
    month_left = x;
}

// Расчёт ежемесячного платежа
double Credit::monthly() {
    if (month_left == 0 || rate == 0.0) {
        return 0.0;
    }
    double monthly_rate = rate / 12.0 / 100.0;
    return debt * monthly_rate / (1 - pow(1 + monthly_rate, -month_left));
}

// Расчёт последнего платежа
double Credit::last_payment() {
    double temp = debt, payment = this->monthly();
    while (temp > payment) {temp -= payment;}
    if (temp < 0) {temp += payment;}
    return temp;
}

// Расчёт общего числа уплаченных банку денег
double Credit::all_payments() {
	double payment = (this->monthly()) * (month_left-1) + this->last_payment();
	return payment;
}

// Расчёт остатка долга на определенном месяце
double Credit::debt_on(unsigned month) {
    if (month > month_left) {
        return 0.0;
    }

    double temp = debt, monthly_payment = this->monthly();
    for (unsigned i = 0; i < month; i++) {
        temp -= monthly_payment - (debt * rate / 12.0 / 100.0);
    }
    return temp;
}

// Расчёт сэкономленной суммы при досрочном погашении на месяце month
double Credit::early_repay_diff(unsigned month) {
    if (month <= 0 || month > month_left) {
        return 0.0;
    }
    return debt - this->debt_on(month);
}

// Расчёт количества месяцев, оставшихся после досрочного платежа payment в месяц month для уменьшения срока
double Credit::part_repay_Period(double payment, unsigned month) {
    if (month > month_left) {
        return 0.0;
    }
    double new_month_left = -log(1 - (this->debt_on(month) - payment) / (this->monthly() * debt)) / log(1 + rate / 12.0 / 100.0);

    return new_month_left;
}

// Расчёт размера выплаты, изменившейся после досрочного платежа payment в месяц month для уменьшения выплат
double Credit::part_repay_Payment(double payment, unsigned month) {
    if (month > month_left) {
        return 0.0;
    }
    return (debt - payment) * rate / 12.0 / 100.0 / (1 - pow(1 + rate / 12.0 / 100.0, -month_left));
}

// Меняет параметры кредита как при внесении досрочного платежа payment в месяц month
void Credit::make_payment(unsigned month, char mode = 'n', double extra_payment = 0.0) {
    if (month > month_left || (mode != "p" && mode != "m")) {
        return;
    }

    if (mode == p) {
    	debt = debt_on(month)-payment;
    	rate = this->part_repay_Payment(payment, month) * month_left * 12 / debt * 100.0;
        month_left -= 1;
    }
    else {
    	debt = debt_on(month)-payment;
    	month_left = part_repay_Period(payment, month);
    }

}