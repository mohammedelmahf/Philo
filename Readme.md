


                        Scenario: Philosopher Thread vs Monitor Thread
                        
                    +----------------------+        +------------------------+
                    | Philosopher Thread   |        | Monitor (Death Checker)|
                    +----------------------+        +------------------------+
                    |                      |        |                        |
                    | LOCK meal_lock       |        |                        |
                    |--------------------->|        |                        |
                    |                      |        |                        |
                    | SET born_time        |        |                        |
                    | SET last_meal        |        |                        |
                    |                      |        |                        |
                    | UNLOCK meal_lock     |        |                        |
                    |--------------------->|        |                        |
                    |                      |        |                        |
                    +----------------------+        |                        |
                                                    |                        |
                                                    | WAIT for lock...       |
                                                    |------------------------|
                                                    | LOCK meal_lock         |
                                                    | READ last_meal         |
                                                    | UNLOCK meal_lock       |
                                                    +------------------------+
