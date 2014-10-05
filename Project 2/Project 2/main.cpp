//
//  main.cpp
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "Item.h"
#include "PopCan.h"
#include "Flower.h"
#include "Daisy.h"

using namespace std;

PopCan* inputPop()
{
    string flavor;
    
    cout << "enter flavor of soda pop (no spaces): ";
    cin >> flavor;
    
    return new PopCan(flavor);
}

Flower* inputFlower()
{
    string color;
    
    cout << "enter color of flower: ";
    cin >> color;
    
    return new Flower(color);
}

int main(int argc, const char* argv[])
{
    // *** Part 1 *** \\
    
    Item** shoppingCart = nullptr;
    
    cout << "JCCC General Store" << endl;
    
    int numberOfItems = 0;
    
    cout << "Enter number of items you want to buy: ";
    cin >> numberOfItems;
    
    shoppingCart = new Item*[numberOfItems];
    
    for (int i = 0; i < numberOfItems; i++)
    {
        Item* newItem;
        
    redo:
        cout << "1) Pop Can, 2) Flower, 3) Daisy. Select: ";
        
        short selection;
        
        cin >> selection;
        
        switch (selection)
        {
            case 1:
                newItem = inputPop();
                break;
            case 2:
                newItem = inputFlower();
                break;
            case 3:
                newItem = new Daisy();
                break;
            default:
                cout << "incorrect selection" << endl;
                goto redo;
                break;
        }
        
        shoppingCart[i] = newItem;
        
        cout << "item added to cart." << endl;
    }
    
    cout << endl << "Number of items: " << numberOfItems;
    
    double grandTotal = 0.00;
    
    for (int i = 0; i < numberOfItems; i++)
    {
        grandTotal += (*shoppingCart[i]).getPrice();
    }
    
    cout << "\tGrand Total: " << '$' << fixed << setprecision(2) << grandTotal << endl;
    
    cout << "Performing each item's action..." << endl;
    
    for (int i = 0; i < numberOfItems; i++)
    {
        (*shoppingCart[i]).doSomething();
    }
    
    cout << "Freeing up memory..." << endl;
    for (int i = 0; i < numberOfItems; i++)
    {
        delete shoppingCart[i];
    }
    
    delete[] shoppingCart;
    
    cout << "\n\tPart 2\n" << endl;
    
    // *** Part 2 *** \\
    
    Item* itemItem;
    Daisy daisyDaisy;
    Flower flowerFlower = Flower("Pink");
    PopCan fantaFanta = PopCan("Fanta");
    PopCan rootBeer = PopCan("Root Beer");
    Flower yellowFlower = Flower("Yellow");
    
    cout << "Color of Daisy is: " << daisyDaisy.Flower::getColor() << endl;
    cout << "ID Number of Daisy is: " << daisyDaisy.Item::getIdNumber() << endl;
    cout << "ID Number of Base Flower is: " << daisyDaisy.Flower::getIdNumber() << endl;
    
    cout << "Base Flower of Daisy Action:" << endl;
    daisyDaisy.Flower::doSomething();
    
    cout << "Color of Flower is: " << flowerFlower.getColor() << endl;
    
    itemItem = &daisyDaisy;
    
    cout << "ID Number of Item is: " << itemItem->getIdNumber() << endl;
    
    itemItem->doSomething();
    
    cout << "Fanta action:\n";
    fantaFanta.doSomething();
    
    cout << "Base Item action:\n";
    fantaFanta.Item::doSomething();
    
    cout << "Base Item Name: " << fantaFanta.getName() << endl;
    
    itemItem = &fantaFanta;
    
    itemItem->doSomething();
    
    cout << fixed << "Price of root beer is: " << '$' << setprecision(2) << rootBeer.getPrice() << endl;
    
    cout << yellowFlower.getName() << endl;
    
    cout << '\n';
    cout.flush();
    
    return 0;
}
