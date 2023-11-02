//Класс Непомнящих Станислава

#ifndef CREDIT_H
#define CREDIT_H

#include <string>
#include <cmath>

///Объект: Кредит
class Credit {
private:
	///Условия кредита
	//Сумма кредита
	double debt;
	//Процентная ставка
	double rate;
	//Срок кредита
	unsigned month_left;

public:
	//Конструктор
	Credit();

	//Геттеры всех переменных
	double get_debt();
	double get_rate();
	double get_month_left();

	//Сеттеры всех переменных
	void set_debt(double x);
	void set_rate(double x);
	void set_month_left(unsigned x);

	//Расчёт ежемесячного платежа
	double monthly();

	//Расчёт последнего платежа, так как он может быть меньше основного
	double last_payment();

	//Расчёт общего числа денег, уплаченных банку
	double all_payments();

	//Расчёт остатка долга на определенном месяце
	double debt_on(unsigned month);

	//Расчёт сэкономленной суммы при досрочном погашении на месяце month
	double early_repay_diff(unsigned month);

	//Расчёт количества месяцев, оставшихся после досрочного платежа payment в месяц month для уменьшения срока
	double part_repay_Period(double payment, unsigned month);

	//Расчёт размера выплаты, изменившейся после досрочного платежа payment в месяц month для уменьшения выплат
	double part_repay_Payment(double payment, unsigned month);

	//Меняет параметры кредита как при внесении досрочного платежа payment в месяц month (без возможности возврата обратно!)
	//p - для уменьшения выплат; m - для уменьшения срока
	double make_part_repay(double payment, unsigned month, char mode);

};

#endif //CREDIT_H