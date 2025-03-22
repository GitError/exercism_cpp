#include "hellmath.h"

namespace hellmath {
	bool display_post(AccountStatus poster, AccountStatus viewer) {
		switch (poster) {
		case AccountStatus::troll:
			switch (viewer) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::guest:
			switch (viewer) {
			case AccountStatus::user:
				return false;
			default:
				return true;
			}
		case AccountStatus::user:
			switch (viewer) {
			case AccountStatus::guest:
				return true;
			default:
				return true;
			}
		case AccountStatus::mod:
			return true;
		default:
			return false;
		}
	}

	bool permission_check(Action action, AccountStatus account) {
		switch (action) {
		case Action::read:
			return true;
		case Action::write:
			switch (account) {
			case AccountStatus::guest:
				return false;
			default:
				return true;
			}
		case Action::remove:
			switch (account) {
			case AccountStatus::mod:
				return true;
			default:
				return false;
			}
		default:
			return false;
		}
	}

	bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
		switch (player1) {
		case AccountStatus::troll:
			switch (player2) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::guest:
			return false;
		default:
			switch (player2) {
			case AccountStatus::guest:
				return false;
			case AccountStatus::troll:
				return false;
			default:
				return true;
			}
		}
	}

	bool has_priority(AccountStatus account1, AccountStatus account2) {
		switch (account1) {
		case AccountStatus::troll:
			return false;
		case AccountStatus::guest:
			switch (account2) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::user:
			switch (account2) {
			case AccountStatus::troll:
			case AccountStatus::guest:
				return true;
			default:
				return false;
			}
		case AccountStatus::mod:
			switch (account2) {
			case AccountStatus::troll:
			case AccountStatus::guest:
			case AccountStatus::user:
				return true;
			default:
				return false;
			}
		default:
			return false;
		}
	}
}