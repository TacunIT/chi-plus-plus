---
layout:     pagina
class:      elenco
title:      Diario di bordo
permalink:  /log/
excerpt:    ""
---

<section class="elenco post">
    {% for post in site.posts %}
        {% if post.tags contains "log" %}
        <div class="log">
            <a class="more" href="{{ post.url }}">
                <h3>{{ post.title }}</h3>
            </a>
            <p class="data">{{ post.date | date_to_string }}</p>
            <p class="tag"><label>tag</label> {{ post.tags | sort | join: ", " }}</p>
            {{ post.og_desc }}<br />
            <a class="more" href="{{ post.url | relative_url}}">leggi tutto</a>
        </div>
        {% endif %}
    {% endfor %}
</section>
