#include "Master.h"

PhotoPtr Master::createPhoto(string name) {
    PhotoPtr photo(new Photo());
    medias[name] = photo;
    return photo;
}

VideoPtr Master::createVideo(string name) {
    VideoPtr video(new Video());
    medias[name] = video;
    return video;
}

FilmPtr Master::createFilm(string name) {
    FilmPtr film(new Film());
    medias[name] = film;
    return film;
}

GroupPtr Master::createGroup(string name) {
    GroupPtr group(new Group());
    groups[name] = group;
    return group;
}

void Master::printObject(string name) const {
    auto it = medias.find(name);
    if(it == medias.end()) {
        cout << "No media named " << name << " !\n" << endl;
    } else {
        it->second->print_values(cout);
    }
}

void Master::printGroup(string name) const {
    auto it = groups.find(name);
    if(it == groups.end()) {
        cout << "No group named " << name << " !\n" << endl;
    } else {
        it->second->print_values(cout);
    }
}

void Master::play(string name) const {
    auto it = medias.find(name);
    if(it == medias.end()) {
        cout << "No media named " << name << " !\n" << endl;
    } else {
        it->second->play_media();
    }
}

void Master::deleteObject(string name) {
    auto it_media = medias.find(name);
    if(it_media == medias.end()) {
        cout << "No media named " << name << " !\n" << endl;
    } else {
        for(auto it_group : groups) {
            GroupPtr group = it_group.second;
            _List_iterator<MediaPtr> begin = group->begin();
            _List_iterator<MediaPtr> end = group->end();
            MediaPtr val = it_media->second;
            auto found_it =find(begin, end, val);
            if(found_it != end) {
                group->erase(found_it);
            }
        }
        medias.erase(name);
    }
}

void Master::deleteGroup(string name) {
    auto it = groups.find(name);
    if(it == groups.end()) {
        cout << "No group named " << name << " !\n" << endl;
    } else {
        groups.erase(name);
    }
}