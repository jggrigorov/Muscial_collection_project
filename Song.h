#pragma once
#include<iostream>
#include<fstream>
#include<string>
class Song {
private:
	std::string name;
	std::string author;
	std::string genre;
	std::string album;
	int release_year;
	double rating;

	void copy_song(const Song&);
	void delete_song();

public:
	Song();
	Song(const Song&);
	Song& operator=(const Song&);
	~Song();

	void set_name(std::string);
	void set_author(std::string);
	void set_genre(std::string);
	void set_album(std::string);
	void set_release_year(int);
	void set_rating(double);

	std::string get_name()const;
	std::string get_author()const;
	std::string get_genre()const;
	std::string get_album()const;
	int get_release_year()const;
	double get_rating()const;

	void print()const;
};
void Song::copy_song(const Song& other) {
	name = other.name;
	author = other.author;
	genre = other.genre;
	album = other.album;
	release_year = other.release_year;
	rating = other.rating;
}
void Song::delete_song() {
	name.clear();
	author.clear();
	genre.clear();
	album.clear();
}
Song::Song() {
	name = "";
	author = "";
	genre = "";
	album = "";
	release_year = 0;
	rating = 0.0;
}
Song::Song(const Song& other) {
	copy_song(other);
}
Song& Song::operator= (const Song & other){
	if (this != &other) {
		delete_song();
		copy_song(other);
	}
	return *this;
}
Song::~Song() {
	delete_song();
}

void Song::set_name(std::string other_name) {
	name = other_name;
}
void Song::set_author(std::string other_author) {
	author = other_author;
}
void Song::set_genre(std::string other_genre) {
	genre = other_genre;
}
void Song::set_album(std::string other_album) {
	album = other_album;
}
void Song::set_release_year(int other_release_year) {
	release_year = other_release_year;
}
void Song::set_rating(double other_rating) {
	rating = other_rating;
}

std::string Song::get_name()const {
	return name;
}
std::string Song::get_author()const {
	return author;
}
std::string Song::get_genre()const {
	return genre;
}
std::string Song::get_album()const {
	return album;
}
int Song::get_release_year()const {
	return release_year;
}
double Song::get_rating()const {
	return rating;
}
void Song::print()const {
	std::cout << name << std::endl;
	std::cout << author << std::endl;
	std::cout << genre << std::endl;
	std::cout << album << std::endl;
	std::cout << release_year << std::endl;
	std::cout << rating << std::endl;
}