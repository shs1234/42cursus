#include "Account.hpp"

static int	Account::getNbAccounts( void );
static int	Account::getTotalAmount( void );
static int	Account::getNbDeposits( void );
static int	Account::getNbWithdrawals( void );
static void	Account::displayAccountsInfos( void );

Account::Account( int initial_deposit );
Account::~Account( void );

void	AccountmakeDeposit( int deposit );
bool	AccountmakeWithdrawal( int withdrawal );
int     AccountcheckAmount( void ) const;
void	AccountdisplayStatus( void ) const;