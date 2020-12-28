
#ifndef DECOMPILE_H_
#define DECOMPILE_H_

#include "Opcodes.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
class Regex;

struct Instruction {

	Instruction(size_t loc, uint8_t o, int16_t n)
		: pc(loc), opcode(o), next(n) {}
	virtual ~Instruction() = default;

	virtual void print() const = 0;

	size_t pc;
	uint8_t opcode;
	int16_t next;
};

struct InstructionBol : Instruction {
	InstructionBol(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "BOL -> " << pc + next << std::endl;
	}
};
struct InstructionEol : Instruction {
	InstructionEol(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "EOL -> " << pc + next << std::endl;
	}
};
struct InstructionBranch : Instruction {
	InstructionBranch(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "BRANCH -> " << pc + next << std::endl;
	}
};
struct InstructionEnd : Instruction {
	InstructionEnd(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "END -> " << pc + next << std::endl;
	}
};
struct InstructionQuestion : Instruction {
	InstructionQuestion(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "QUESTION -> " << pc + next << std::endl;
	}
};
struct InstructionStar : Instruction {
	InstructionStar(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "STAR -> " << pc + next << std::endl;
	}
};
struct InstructionLazyStar : Instruction {
	InstructionLazyStar(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "LAZY_STAR -> " << pc + next << std::endl;
	}
};
struct InstructionPlus : Instruction {
	InstructionPlus(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "PLUS -> " << pc + next << std::endl;
	}
};
struct InstructionOpen : Instruction {
	InstructionOpen(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "OPEN(" << opcode - OPEN << ") -> " << pc + next << std::endl;
	}
};
struct InstructionClose : Instruction {
	InstructionClose(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "CLOSE(" << opcode - CLOSE << ") -> " << pc + next << std::endl;
	}
};
struct InstructionNothing : Instruction {
	InstructionNothing(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NOTHING -> " << pc + next << std::endl;
	}
};
struct InstructionSpace : Instruction {
	InstructionSpace(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "SPACE -> " << pc + next << std::endl;
	}
};
struct InstructionBoWord : Instruction {
	InstructionBoWord(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "BOWORD -> " << pc + next << std::endl;
	}
};
struct InstructionEoWord : Instruction {
	InstructionEoWord(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "EOWORD -> " << pc + next << std::endl;
	}
};
struct InstructionAny : Instruction {
	InstructionAny(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "ANY -> " << pc + next << std::endl;
	}
};
struct InstructionLetter : Instruction {
	InstructionLetter(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "LETTER -> " << pc + next << std::endl;
	}
};
struct InstructionDigit : Instruction {
	InstructionDigit(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "DIGIT -> " << pc + next << std::endl;
	}
};
struct InstructionNegBehindClose : Instruction {
	InstructionNegBehindClose(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NEG_LOOK_BEHIND_CLOSE -> " << pc + next << std::endl;
	}
};
struct InstructionWordChar : Instruction {
	InstructionWordChar(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "WORD_CHAR -> " << pc + next << std::endl;
	}
};
struct InstructionBack : Instruction {
	InstructionBack(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "BACK -> " << pc - next << std::endl;
	}
};
struct InstructionNegAheadOpen : Instruction {
	InstructionNegAheadOpen(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NEG_LOOK_AHEAD_OPEN -> " << pc - next << std::endl;
	}
};
struct InstructionLookAheadClose : Instruction {
	InstructionLookAheadClose(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "LOOK_AHEAD_CLOSE -> " << pc - next << std::endl;
	}
};
struct InstructionPosAheadOpen : Instruction {
	InstructionPosAheadOpen(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "POS_LOOK_AHEAD_OPEN -> " << pc - next << std::endl;
	}
};
struct InstructionNotDelim : Instruction {
	InstructionNotDelim(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NOT_DELIM -> " << pc - next << std::endl;
	}
};
struct InstructionSpaceNL : Instruction {
	InstructionSpaceNL(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "SPACE_NL -> " << pc - next << std::endl;
	}
};
struct InstructionNotSpace : Instruction {
	InstructionNotSpace(size_t loc, uint8_t o, int16_t n)
		: Instruction(loc, o, n) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NOT_SPACE -> " << pc - next << std::endl;
	}
};

struct InstructionExactly : Instruction {
	InstructionExactly(size_t loc, uint8_t o, int16_t n, std::string s)
		: Instruction(loc, o, n), set(std::move(s)) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "EXACTLY [" << set << "] -> " << pc + next << std::endl;
	}

	std::string set;
};
struct InstructionAnyOf : Instruction {
	InstructionAnyOf(size_t loc, uint8_t o, int16_t n, std::string s)
		: Instruction(loc, o, n), set(std::move(s)) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "ANY_OF [" << set << "] -> " << pc + next << std::endl;
	}

	std::string set;
};
struct InstructionAnyBut : Instruction {
	InstructionAnyBut(size_t loc, uint8_t o, int16_t n, std::string s)
		: Instruction(loc, o, n), set(std::move(s)) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "ANY_BUT [" << set << "] -> " << pc + next << std::endl;
	}

	std::string set;
};
struct InstructionSimilar : Instruction {
	InstructionSimilar(size_t loc, uint8_t o, int16_t n, std::string s)
		: Instruction(loc, o, n), set(std::move(s)) {}

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "SIMILAR [" << set << "] -> " << pc + next << std::endl;
	}

	std::string set;
};

struct InstructionBrace : Instruction {
	InstructionBrace(size_t loc, uint8_t o, int16_t n, uint16_t min_, uint16_t max_)
		: Instruction(loc, o, n), min(min_), max(max_) {}
	uint16_t min;
	uint16_t max;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "SIMILAR [" << min << ", " << max << "] -> " << pc + next << std::endl;
	}
};

struct InstructionBackRef : Instruction {
	InstructionBackRef(size_t loc, uint8_t o, int16_t n, uint16_t i)
		: Instruction(loc, o, n), index(i) {}
	uint16_t index;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "BACK_REF [" << index << "] -> " << pc + next << std::endl;
	}
};
struct InstructionInitCount : Instruction {
	InstructionInitCount(size_t loc, uint8_t o, int16_t n, uint16_t i)
		: Instruction(loc, o, n), operand(i) {}
	uint16_t operand;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "INIT_COUNT [" << operand << "]-> " << pc - next << std::endl;
	}
};
struct InstructionIncCount : Instruction {
	InstructionIncCount(size_t loc, uint8_t o, int16_t n, uint16_t i)
		: Instruction(loc, o, n), operand(i) {}
	uint16_t operand;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "INC_COUNT [" << operand << "]-> " << pc - next << std::endl;
	}
};

struct InstructionTestCount : Instruction {
	InstructionTestCount(size_t loc, uint8_t o, int16_t n, uint16_t i, uint16_t t)
		: Instruction(loc, o, n), index(i), test(t) {}
	uint16_t index;
	uint16_t test;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "TEST_COUNT <" << index << ", " << test << "> -> " << pc + next << std::endl;
	}
};

struct InstructionNegBehindOpen : Instruction {
	InstructionNegBehindOpen(size_t loc, uint8_t o, int16_t n, uint16_t o1, uint16_t o2)
		: Instruction(loc, o, n), op1(o1), op2(o2) {}
	uint16_t op1;
	uint16_t op2;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "NEG_LOOK_BEHIND_OPEN <" << op1 << ", " << op2 << "> -> " << pc + next << std::endl;
	}
};
struct InstructionPosBehindOpen : Instruction {
	InstructionPosBehindOpen(size_t loc, uint8_t o, int16_t n, uint16_t o1, uint16_t o2)
		: Instruction(loc, o, n), op1(o1), op2(o2) {}
	uint16_t op1;
	uint16_t op2;

	void print() const override {
		std::cout << std::setw(4) << pc << ": "
				  << "POS_LOOK_BEHIND_OPEN <" << op1 << ", " << op2 << "> -> " << pc + next << std::endl;
	}
};

std::vector<Instruction *> decompileRegex(const Regex &re);

#endif
