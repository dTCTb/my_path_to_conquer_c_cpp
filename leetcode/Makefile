LEETCODE=1 539 884 179 241 214 386 2707 3043 2416 729 731 641 432 1381 1497 1331 1590 2491 567 1813 2696
LEETCODE_COMPILER_SETTING= -O2 -fsanitize=address
# ASAN_OPTIONS=detect_leaks=1
BIN=./bin

all: $(LEETCODE)

1: 1_two_sum.cpp
	clang++ -o $(BIN)/$@ $<

539: 539_minimum_time_difference.cpp
	clang++ -o $(BIN)/$@ $<

884: 884_uncommon_words_from_two_sentences.cpp
	clang++ -o $(BIN)/$@ $<

179: 179_largest_number.cpp
	clang++ -o $(BIN)/$@ $<
	@$(BIN)/$@

241: 241_different_ways_to_add_parentheses.cpp
	clang++ -o $(BIN)/$@ $<
	@$(BIN)/$@

214: 214_shortest_palindrome.cpp
	clang++ -o $(BIN)/$@ $< -g
	# @$(BIN)/$@

386: 386_lexicographical_numbers.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

2707: 2707_extra_characters_in_a_string.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

3043: 3043_find_the_length_of_the_longest_common_prefix.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

2416: 2416_sum_of_prefix_scores_of_strings.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

729: 729_my_calendar_I.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

731: 731_my_calendar_II.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

641: 641_design_circular_deque.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

432: 432_allone_data_structure.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

1381: 1381_design_a_stack_with_increment_operation.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@

1497: 1497_check_if_array_pairs_are_divisible_by_k.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@

1331: 1331_rank_transform_of_an_array.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@

1590: 1590_make_sum_divisible_by_p.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@

2491: 2491_divide_players_into_teams_of_equal_skill.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

567: 567_permutation_in_string.cpp
	clang++ -o $(BIN)/$@ $< -g
	@$(BIN)/$@

1813: 1813_sentence_similarity_iii.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@

2696: 2696_minimum_string_length_after_removing_substrings.cpp
	clang++ -o $(BIN)/$@ $< -g $(LEETCODE_COMPILER_SETTING)
	@$(BIN)/$@
