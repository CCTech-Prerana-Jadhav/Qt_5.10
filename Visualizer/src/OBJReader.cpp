#include <QString>
#include <fstream>
#include <iostream>
#include "OBJReader.h"
#include "Triangulation.h"
#include "Point.h"
#include "Triangle.h"
#include <vector>
#include <sstream>
#include <cassert>
#include <map>

using namespace std;

OBJReader::OBJReader()
{
}

OBJReader::~OBJReader()
{
}

void OBJReader::read(const string& fileName, Triangulation& triangulation)
{
    map<double, int> uniqueMap;
    double xyz[3];
    double normalXYZ[3];
    string str1;
    string str2;
    string str3;
    //vector<int> pointIndices;
    vector<Point> vertices;
    vector<Point> normals;


    ifstream infile(fileName);
    //assert(infile && "Error: Could not open file");
    if (infile.is_open())
    {

        string line;

        while (getline(infile, line))
        {
            stringstream ss(line);
            string word;
            while (ss >> word)
            {
                if (word == "v")
                {
                    ss >> xyz[0] >> xyz[1] >> xyz[2];

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(xyz[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.UniqueNumbers.push_back(xyz[i]);
                            uniqueMap[xyz[i]] = triangulation.UniqueNumbers.size() - 1;
                            pt[i] = triangulation.UniqueNumbers.size() - 1;

                        }
                        else
                        {
                            pt[i] = pair->second;

                        }

                    }
                    vertices.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "vn")
                {
                    ss >> normalXYZ[0] >> normalXYZ[1] >> normalXYZ[2];

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(normalXYZ[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.UniqueNumbers.push_back(normalXYZ[i]);
                            uniqueMap[normalXYZ[i]] = triangulation.UniqueNumbers.size() - 1;
                            pt[i] = triangulation.UniqueNumbers.size() - 1;

                        }
                        else
                        {
                            pt[i] = pair->second;
                        }
                    }
                    normals.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "f")
                {
                    ss >> str1 >> str2 >> str3;
                    QString str_s = QString::fromStdString(str1);
                    QStringList splitlist =  str_s.split("/");
                    int FirstPointIndex = stoi(str1.substr(0, 1)) - 1;
                    int SecondPointIndex = stoi(str2.substr(0, 1)) - 1;
                    int ThirdPointIndex = stoi(str3.substr(0, 1)) - 1;
                    int normalIndex = stoi(str3.substr(4, 1)) - 1;

                    triangulation.Triangles.push_back(Triangle(normals[normalIndex], vertices[FirstPointIndex], vertices[SecondPointIndex], vertices[ThirdPointIndex] ));
                }
            }
        }
    }
}