#include "deck.h"

<<<<<<< HEAD
/**
 * val_cmp - Performs a case-insensitive character comparison of two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: The comparison value. -1 for less, 1 for greater, and 0 for equal.
 */
int val_cmp(const char *str1, const char *str2)
{
	int i = 0;
	char a, b;

	if (str1 == NULL)
		return (str2 == NULL ? 0 : -1);
	if (str2 == NULL)
		return (1);
	for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		a = ((str1[i] >= 'A') && (str1[i] <= 'Z') ? str1[i] + 32 : str1[i]);
		b = ((str2[i] >= 'A') && (str2[i] <= 'Z') ? str2[i] + 32 : str2[i]);
		if (a > b)
			return (1);
		else if (a < b)
			return (-1);
	}
	if (str1[i] == '\0')
		return (str2[i] == '\0' ? 0 : -1);
	return (1);
}

/**
 * card_key - Computes the sorting key of a playing card.
 * @card: The playing card.
 *
 * Return: The key that can be used to sort the card.
 */
int card_key(const card_t *card)
{
	int rank = -1, base = 0, i = 0;
	char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King", NULL
	};

	if (card == NULL)
		return (-2);
	while (values[i] != NULL)
	{
		if (val_cmp(card->value, values[i]) == 0)
		{
			rank = base + i;
			break;
		}
		i++;
	}
	return (rank + (13 * card->kind));
}

/**
 * swap_nodes - Swaps two nodes in a linked list.
 * @list: A pointer to the head of the linked list.
 * @l: The left item to swap.
 * @r: The right item to swap.
 */
void swap_nodes(deck_node_t **list, deck_node_t *l, deck_node_t *r)
{
	deck_node_t *tmp0 = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	if ((l == NULL) || (r == NULL) || (list == NULL) || (l == r))
		return;
	tmp0 = l->prev, tmp1 = l->next, tmp2 = r->prev, tmp3 = r->next;
	if (l->prev == r)
	{
		l->next = r, l->prev = tmp2, r->next = tmp1, r->prev = l;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp1 != NULL)
			tmp1->prev = r;
	}
	else if (l->next == r)
	{
		l->next = tmp3, l->prev = r, r->next = l, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	else
	{
		l->next = tmp3, l->prev = tmp2, r->next = tmp1, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp1 != NULL)
			tmp1->prev = r;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	if (l->prev == NULL)
		*list = l;
	if (r->prev == NULL)
		*list = r;
}

/**
 * sort_deck - Sorts a deck of cards using the insertion sort algorithm.
 * @deck: The deck of cards to sort.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node0 = NULL, *node1 = NULL, *node2 = NULL, *tmp = NULL;

	if (deck != NULL)
	{
		node0 = *deck == NULL ? NULL : (*deck)->next;
		while (node0 != NULL)
		{
			node1 = node0;
			node2 = node1->prev;
			node0 = node0->next;
			while ((node1 != NULL) && (node2 != NULL))
			{
				tmp = node2;
				if (card_key(node2->card) > card_key(node1->card))
				{
					swap_nodes(deck, node1, node2);
				}
				node1 = tmp;
				node2 = tmp->prev;
			}
		}
=======
#include <stdio.h>
void sort_suit(deck_node_t **deck);
void sort_val(deck_node_t **deck);
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2);
int vcmp(const card_t *card1, const card_t *card2);
/**
 * sort_deck - sorts a 52 card deck
 * @deck: deck to sort
 *
 * Return: Always 0 (ok)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	sort_suit(deck);
	sort_val(deck);
}

/**
 * sort_suit - sorts a 52 card deck by suit
 * @deck: deck to sort
 */
void sort_suit(deck_node_t **deck)
{
	deck_node_t *forw, *tmp;

	for (forw = (*deck)->next; forw && forw->prev; forw = forw->next)
	{
		for (; forw && forw->prev && forw->card->kind <
			     forw->prev->card->kind; forw = forw->prev)
		{
			tmp = forw->prev;
			swap(deck, tmp, forw);
			forw = forw->next;
		}
	}
}

/**
 * sort_val - sorts a 52 card deck staticly by value
 * @deck: deck to sort
 */
void sort_val(deck_node_t **deck)
{
	deck_node_t *f, *tmp;

	for (f = (*deck)->next; f && f->prev; f = f->next)
	{
		for (; f && f->prev && vcmp(f->card, f->prev->card) &&
			     f->card->kind == f->prev->card->kind;
		     f = f->prev)
		{
			tmp = f->prev;
			swap(deck, tmp, f);
			f = f->next;
		}
	}
}
/**
 * swap - swaps 2 consecutive cards of a doubly linked list
 * Used in the insertion algorithm
 * @deck: Head node for the deck
 * @card1: The first card to swap
 * @card2: The second card to swap
 */
void swap(deck_node_t **deck, deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev, *next;

	prev = card1->prev;
	next = card2->next;

	if (prev != NULL)
		prev->next = card2;
	else
		*deck = card2;
	card1->prev = card2;
	card1->next = next;
	card2->prev = prev;
	card2->next = card1;
	if (next)
		next->prev = card1;
}

/**
 * vcmp - compares 2 card values
 * @card1: The first card to compare
 * @card2: The second card to compare
 *
 * Return: 1 if less than, 0 if greater or equal to
 */
int vcmp(const card_t *card1, const card_t *card2)
{
	char char1 = card1->value[0], char2 = card2->value[0];
	const char *ord[14] = {"Ac", "1", "2", "3", "4", "5", "6",
			       "7", "8", "9", "10", "Ja", "Qu", "Ki"};
	int idx1 = 0, idx2 = 0, i;

	if ((char1 >= 48 && char1 <= 57) && (char2 >= 49 &&
					     char2 <= 57))
	{
		if (card1->value[1] == '0')
			char1 = 58;
		if (card2->value[1] == '0')
			char2 = 58;
		return (char1 < char2);
	}
	else
	{
		for (i = 0; i < 14; i++)
		{
			if (card1->value[0] == ord[i][0] &&
			    card1->value[1] == ord[i][1])
				idx1 = i;
			if (card2->value[0] == ord[i][0] &&
			    card2->value[1] == ord[i][1])
				idx2 = i;
		}
		return (idx1 < idx2);
>>>>>>> fcb03bca55b452920d61c2c27494aa0d9c1ea789
	}
}
