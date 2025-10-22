# \[ACM.Dev\] [Mann Vs Machine](https://wiki.teamfortress.com/wiki/Mann_vs._Machine): Poker Bot Starter Code

## Submission Guidelines
Welcome to the Poker Bot Tournament!
To ensure smooth gameplay and fair evaluation, all teams must follow the submission guidelines outlined below. Any submissions not adhering to these rules may be disqualified.


### 1. Interface & Bot Behavior
- All participant bots will be executed on our backend servers.
- Your bot will receive the current game state (using the template schemas provided) and is expected to return a single valid poker action on its turn.
- The game engine will handle: progressing the game state, dealing cards, enforcing the rules.
- Your code must not interact with external services or modify how the game state is provided.

### 2. Submission Format
- You should only submit one file.
- Do not modify the `bet(state: GameState) -> int` function signature or class definitions in the code template.

### 3. Template & Schema
- Do not modify the required function signatures or class definitions in the template.
- Additional helper functions/classes are allowed as long as they don’t interfere with the interface.
- Python Template Snippet:
```python
class Pot:
    value: int  # money in pot
    players: list[str]  # players vying for this pot, team_ids

# cards are defined as a 2 character string [value][suite]
# where 1st char: a(2-9)tjqk, 2nd char: s d c h
class GameState:
    index_to_action: int
    index_of_small_blind: int
    players: list[str]
    player_cards: list[str]
    held_money: list[int]
    bet_money: list[int]  # -1 for fold, 0 for check/hasn't bet
    community_cards: list[str]
    pots: list[Pot]
    small_blind: int
    big_blind: int
```
Example GameState:
```JSON
{
"index_to_action": 2,
"index_of_small_blind": 0,
"players": ["team_id0", "team_id1", "team_id2"],
"player_cards": ["2s", "7s"],
"held_money": [100, 200, 300],
"bet_money": [20, -1, 0],
"community_cards": ["ac", "2h", "2d"],
"pots": [{ "value": 50, "players": ["team_id0", "team_id2"] }],
"small_blind": 5,
"big_blind": 10
}
```
Example Interpretation:
- Betting round after the flop.
- Player 0 bet 20, Player 1 folded, action is on Player 2.
- Player 2 has trips with 2s and 7s.

### 4. Functionality & Performance
- Bots must make legal poker moves according to the game rules.
- No access to: Filesystem, Network, External resources.
- Each bot has 5 seconds per move. Exceeding this limit may result in folding or disqualification.

### 5. Code Specification & Libraries
- Python 3.11
- We only allow standard python libraries (support for mainstream external libraries will come next time)
- List of black listed standard libraries can be found [here](https://docs.google.com/document/d/1Q78tdVFAZIFt0ZWEgNG65nDDAlbt6rcG5o21waeZprA/edit?usp=sharing).

### 6. Submission Deadline
- All submissions must be received before 11:59 PM on November 6, 2025.
- Late submissions will not be accepted.

### 7. Submission Method
- Submit through the official tournament [dashboard](https://acm-poker-tournament.vercel.app/dashboard).
- If not using ML, only .py or .cpp files are accepted.
- **Do not include**:
  - Unrelated code
  - Personal data
  - System or binary files


### 8. Testing Your Bot
- A local tournament simulator will be provided for participants.
- We strongly recommend testing your bot locally to ensure it:
  - Runs without errors
  - Complies with the template interface
  - Performs within the time limit

### 9. Code Review
- All submissions will undergo a code review.
- Review checks for: Compliance with template and libraries, Illegal or unfair behavior, Runtime safety and performance.
- Non-compliant bots will be disqualified.

### 10. Disqualification Criteria
- The bot throws errors or crashes during the game.
- It fails to follow the required interface.
- It uses illegal libraries or external resources.
- It exceeds time limits repeatedly.
- It makes illegal moves (see below).

### 11. Things to Note
- Illegal moves will be automatically treated as folding.
- Examples: Checking when a raise is required, Betting less than the required minimum.
- If you have special requests (e.g., library whitelisting, accommodations), contact us through Discord before the submission deadline.
- The tournament backend is designed for fairness — attempts to exploit the system will result in immediate disqualification.
- Bots are called only during their own turn; they should not rely on global state or other bots’ internals.

### 12. Contact & Support
For technical issues, clarifications, or library accommodation requests:
- Join our [Discord server](https://discord.gg/p6rcUUjWaU)
- Or email us at: acm.dev.ucsb@gmail.com