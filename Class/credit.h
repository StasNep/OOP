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
	//Конструктор по умолчанию
	Credit();

	//Конструктор с начальными параметрами
	Credit(double Debt, double Rate, unsigned Left);

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

	//Меняет параметры кредита как при внесении платежа в месяц month (без возможности возврата обратно!)
	//Аргумент extra_payment необязательный, при его вводе будет перерасчёт кредита, но тогда обязательно нужно выбрать режим mode
	//mode: p - для уменьшения выплат; m - для уменьшения срока
	void make_payment(unsigned month, char mode, double extra_payment);

};

#endif //CREDIT_H