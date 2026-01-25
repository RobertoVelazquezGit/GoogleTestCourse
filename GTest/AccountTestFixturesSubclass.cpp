#include <iostream>
//#include <gtest/gtest.h>
#include "pch.h"
#include <stdexcept>
#include "Account.hpp"

class AccountTestFixtureSubclass : public testing::Test
{
public:
    AccountTestFixtureSubclass();
    virtual ~AccountTestFixtureSubclass();
    void SetUp() override;
    void TearDown() override;
    static void SetUpTestCase();
    static void TearDownTestCase();
protected:
    int* ptr;
    Account account;
};

AccountTestFixtureSubclass::AccountTestFixtureSubclass()
{
    std::cout << "Constructor called\n";
}

AccountTestFixtureSubclass::~AccountTestFixtureSubclass()
{
    std::cout << "Destructor called\n";
}

void AccountTestFixtureSubclass::SetUpTestCase()
{
    std::cout << "SetUpTestCase called\n";
}

void AccountTestFixtureSubclass::TearDownTestCase()
{
    std::cout << "TearDownTestCase called\n";
}

void AccountTestFixtureSubclass::SetUp()
{
    std::cout << "SetUp called\n";
    account.deposit(10.5);
    ptr = new int;
    *ptr = 5;
}

void AccountTestFixtureSubclass::TearDown()
{
    std::cout << "TearDown called\n";
    delete ptr;
}

/////////////////////////////

class AccountTestFixtureChild : public AccountTestFixtureSubclass
{
public:
    AccountTestFixtureChild();
    ~AccountTestFixtureChild();
    void SetUp();
    void TearDown();
    static void SetUpTestCase();
    static void TearDownTestCase();
};


AccountTestFixtureChild::AccountTestFixtureChild()
{
    std::cout << "Constructor called (child)\n";
}

AccountTestFixtureChild::~AccountTestFixtureChild()
{
    std::cout << "Destructor called (child)\n";
}

void AccountTestFixtureChild::SetUpTestCase()
{
    std::cout << "SetUpTestCase called (child)\n";
}

void AccountTestFixtureChild::TearDownTestCase()
{
    std::cout << "TearDownTestCase called (child)\n";
}

void AccountTestFixtureChild::SetUp()
{    
	AccountTestFixtureSubclass::SetUp();  // If forgot to call AccountTestFixture::SetUp() -> crash
    std::cout << "SetUp called (child)\n";
    std::cout << "Ptr = " << (*ptr) << '\n';
    std::cout << "Balance = " << account.getBalance() << '\n';
	// Commented out account.deposit(10.5);  // the balance would be 21.0 in each test
}

void AccountTestFixtureChild::TearDown()
{    
	AccountTestFixtureSubclass::TearDown();  // If forgot to call AccountTestFixture::TearDown() -> memory leak
    std::cout << "TearDown called (child)\n";
}

TEST_F(AccountTestFixtureChild, TestDeposit)
{
    std::cout << "Test body\n";
    ASSERT_EQ(10.5, account.getBalance());
}


TEST_F(AccountTestFixtureChild, TestWithdrawOK)
{
    account.withdraw(3);

    ASSERT_EQ(7.5, account.getBalance());
}


TEST_F(AccountTestFixtureChild, TestWithdrawInsufficientFunds)
{
    ASSERT_THROW(account.withdraw(300), std::runtime_error);
}


TEST_F(AccountTestFixtureChild, TestTransferOK)
{
    Account to;

    account.transfer(to, 2);

    ASSERT_EQ(8.5, account.getBalance());
    ASSERT_EQ(2, to.getBalance());
}


TEST_F(AccountTestFixtureChild, TestTransferInsufficientFunds)
{
    Account to;

    ASSERT_THROW(account.transfer(to, 200), std::runtime_error);
}