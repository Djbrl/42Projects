/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:37:43 by user42            #+#    #+#             */
/*   Updated: 2022/01/27 15:05:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/Fixed.hpp"

#include "../include/Brain.hpp"

std::string generateIdea() {
    const std::string ideas[150] =
    {
        "The cat is sleeping.",
        "I love chocolate ice cream.",
        "Today is a sunny day.",
        "The book on the table is red.",
        "I enjoy playing tennis.",
        "Coffee is my favorite morning drink.",
        "The movie starts at 7 PM.",
        "I need to buy groceries tomorrow.",
        "The dog is chasing its tail.",
        "Music always cheers me up.",
        "I like to take long walks in the park.",
        "Pizza is my guilty pleasure.",
        "The flowers are blooming in the garden.",
        "I'm excited for my upcoming vacation.",
        "The painting on the wall is beautiful.",
        "I'm learning to play the guitar.",
        "I need to do laundry later.",
        "The traffic is terrible during rush hour.",
        "I enjoy watching documentaries.",
        "The computer screen is too bright.",
        "I'm craving a hamburger for lunch.",
        "The baby is finally asleep.",
        "I have a meeting at 10 AM tomorrow.",
        "The mountain view is breathtaking.",
        "I like to read before going to bed.",
        "The phone battery is almost dead.",
        "I'm going to the gym this evening.",
        "The car needs to be washed.",
        "I'm trying a new recipe for dinner.",
        "The email was sent successfully.",
        "I enjoy going for bike rides.",
        "The clock is ticking.",
        "I have a dentist appointment next week.",
        "The sun is setting in the horizon.",
        "I'm going to visit my family this weekend.",
        "The sound of waves is relaxing.",
        "I need to water the plants.",
        "The soccer game ended in a tie.",
        "I'm organizing my closet.",
        "The new smartphone is very expensive.",
        "I enjoy solving crossword puzzles.",
        "The coffee mug is on the table.",
        "I have a headache.",
        "The train arrives in five minutes.",
        "I'm going to watch a movie tonight.",
        "The weather forecast predicts rain.",
        "I need to fix a leaky faucet.",
        "The restaurant has a diverse menu.",
        "I like to go swimming in the summer.",
        "The test results came back negative.",
        "I'm going to a concert next month.",
        "The wifi signal is weak in this room.",
        "I enjoy taking photographs.",
        "The park is crowded on weekends.",
        "I'm going to buy new shoes.",
        "The stars are shining brightly tonight.",
        "I have a job interview tomorrow.",
        "The air conditioner is not working.",
        "I like to meditate in the morning.",
        "The painting needs to be hung on the wall.",
        "I'm going to a friend's birthday party.",
        "The museum has a fascinating exhibit.",
        "I need to clean the windows.",
        "The bus is running late.",
        "I enjoy playing board games with friends.",
        "The cookies are freshly baked.",
        "I have to finish writing a report.",
        "The alarm clock woke me up early.",
        "I'm going to buy groceries after work.",
        "The moon is full tonight.",
        "I like to go hiking in the mountains.",
        "The camera battery needs to be charged.",
        "I'm attending a conference next week.",
        "The printer is out of paper.",
        "I enjoy watching the sunset.",
        "The restaurant is closed on Sundays.",
        "I have a doctor's appointment in the afternoon.",
        "The birds are chirping outside my window.",
        "I'm going to start a new book.",
        "The shoes are too tight.",
        "I need to make a phone call.",
        "The traffic light turned green.",
        "I enjoy listening to classical music.",
        "The refrigerator needs to be cleaned.",
        "I'm going to bake cookies.",
        "The movie theater is packed.",
        "I have a conference call in an hour.",
        "The laptop is running slowly.",
        "I like to go jogging in the park.",
        "The meeting will start at 2 PM.",
        "I need to buy a birthday gift.",
        "The beach is crowded during summer.",
        "I'm going to paint a picture.",
        "The restaurant has a vegetarian option.",
        "I enjoy watching documentaries about nature.",
        "The weather is getting colder.",
        "I have to return library books.",
        "The car broke down on the highway.",
        "I'm going to a yoga class tonight.",
        "The supermarket is open until 10 PM.",
        "I like to go fishing on weekends.",
        "The concert tickets are sold out.",
        "I need to send an email.",
        "The coffee shop has a cozy atmosphere.",
        "I have a meeting with my boss tomorrow.",
        "The movie was released last month.",
        "I'm going to plant flowers in the garden.",
        "The road is under construction.",
        "I enjoy trying new recipes.",
        "The clock is ticking fast.",
        "I need to buy a new phone charger.",
        "The gym is closed for renovation.",
        "I like to read motivational books.",
        "The email contains important information.",
        "I have to attend a wedding next week.",
        "The sun is shining brightly.",
        "I'm going to the theater tonight.",
        "The weather is unpredictable.",
        "I enjoy doing yoga in the morning."
    };
    return ideas[rand() % 100];
}

Brain::Brain()
{
    std::cout << "#Default Brain Constructor" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = generateIdea();
        // std::cout << "idea " << i << " : " << ideas[i] << std::endl;
    }
}

Brain::Brain(const Brain& b)
{
    *this = b;
    std::cout << "#Copy Brain Constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& b)
{
    if (this != &b)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = b.ideas[i];
    }
    std::cout << "#Copy Brain Operator (Deep Copy)" << std::endl;
    return (*this);
}

std::string Brain::returnIdea(int i)
{
    if (i >= 0 && i < 100)
        return ideas[i];
    else
        return "";
}

Brain::~Brain()
{
    std::cout << "#Default Brain Destructor" << std::endl;
}
