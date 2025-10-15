# DO NOT MODIFY

class Pot:
    value: int
    players: list[str]


class GameState:
    index_to_action: int
    index_of_small_blind: int
    players: list[str]
    player_cards: list[str]
    held_money: list[int]
    bet_money: list[int]
    community_cards: list[str]
    pots: list[Pot]
    small_blind: int
    big_blind: int